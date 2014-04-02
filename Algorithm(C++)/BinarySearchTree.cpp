//
//  BinarySearchTree.cpp
//  Algorithm(C++)
//
//  Created by tang dixi on 30/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#include "BinarySearchTree.h"

using namespace std;

#pragma mark - Construct Function

BinarySearchTree::BinarySearchTree(){
    if (!this -> root_) {
        root_ = new BinarySearchTreeNode();
    }
}

BinarySearchTree::BinarySearchTree(const int& value){
    if (!this -> root_) {
        root_ = new BinarySearchTreeNode(value);
    }
}

BinarySearchTree::BinarySearchTree(vector<int> values){
    if (!this -> root_) {
        vector<int>::iterator iter(values.begin());
        root_ = new BinarySearchTreeNode(*iter);
        
        while (iter != values.end()) {
            if (iter != values.begin()) {
                this -> insertNode(*iter);
            }
            iter++;
        }
    }
}

BinarySearchTree::BinarySearchTree(int *preOrder, int *inOrder, const int& length, const int& type){
    if (!this -> root_) {
        if (type == 0) {
            root_ = reBuildTreeThroughPreAndInOrder(preOrder, inOrder, length);
        }
        else{
            root_ = rebuildTreeThroughInAndPostOrder(preOrder, inOrder, length);
        }
    }
}

#pragma mark - Access private variable

BinarySearchTreeNode* BinarySearchTree::root() const{
    return this -> root_;
}

#pragma mark - Basic Function

int BinarySearchTree::depth(){
    BinarySearchTreeNode *root = this -> root();
    return depth(root);
}

int BinarySearchTree::depth(BinarySearchTreeNode *&root){
    if (!root) {
        return 0;
    }
    return depth(root -> left) >= depth(root -> right) ? (depth(root -> left) + 1) : (depth(root -> right) + 1);
}

bool BinarySearchTree::contains(const int& value){
    BinarySearchTreeNode* root = this -> root();
    return contains(root, value);
}

bool BinarySearchTree::contains(BinarySearchTreeNode *node, const int& value){
    if (!node) {
        return false;
    }
    else if (node -> value < value) {
        contains(node -> right, node -> value);
    }
    else {
        contains(node -> left, node -> value);
    }
    return true;
}

void BinarySearchTree::deleteNode(const int&value){
    BinarySearchTreeNode *root = this -> root();
    if (find(value)) {
        deleteNode(value, root);
    }
}

void BinarySearchTree::deleteNode(const int& value, BinarySearchTreeNode *&root){
    if (!root) {
        return ;
    }
    if (value < root -> value){
        deleteNode(value, root -> left);
    }
    else if (root -> right){
        deleteNode(value, root -> right);
    }
    else if (root -> left && root -> right){
        root -> value = findMax(root -> right) -> value;
        deleteNode(root -> value, root -> right);
    }
    else {
        BinarySearchTreeNode *temp = root;
        root = (root -> left ? root -> left : root -> right);
        delete temp;
    }
}

#pragma mark - Find Max or Min Node

void BinarySearchTree::findMin(){
    BinarySearchTreeNode *root = this -> root();
    findMin(root);
}

BinarySearchTreeNode* BinarySearchTree::findMin(BinarySearchTreeNode *&root){
    if (!root) {
        return NULL;
    }
    return findMin(root -> left);
}

void BinarySearchTree::findMax(){
    BinarySearchTreeNode *root = this -> root();
    findMax(root);
}

BinarySearchTreeNode* BinarySearchTree::findMax(BinarySearchTreeNode *&root){
    if (!root) {
        return NULL;
    }
    return findMin(root -> right);
}

#pragma mark - Insert function

void BinarySearchTree::insertNode(vector<int> values){
    for (vector<int>::iterator iter(values.begin()); iter != values.end(); iter++) {
        insertNode(*iter);
    }
}

void BinarySearchTree::insertNode(BinarySearchTreeNode *&root, const int& value){
    if (!root) {
        root = new BinarySearchTreeNode(value);
    }
    else if (root -> value < value) {
        insertNode(root -> right, value);
    }
    else if (root -> value > value) {
        insertNode(root -> left, value);
    }
    else {
        return ;
    }
}

void BinarySearchTree::insertNode(const int& value){
    BinarySearchTreeNode *root = this -> root();
    insertNode(root, value);
}

#pragma mark - Print tree

void BinarySearchTree::print(BinarySearchTreeNode *&currentNode){
    cout << currentNode -> value << ' ';
}

#pragma mark - Traverse tree

// PreOrder Traverse
void BinarySearchTree::preOrderTraverse(){
    BinarySearchTreeNode *root = this -> root();
    preOrderTraverse(root);
}

void BinarySearchTree::preOrderTraverse(BinarySearchTreeNode *&root){
    if (!root) {
        return ;
    }
    print(root);
    preOrderTraverse(root -> left);
    preOrderTraverse(root -> right);
}

// InOrder Traverse
void BinarySearchTree::inOrderTraverse(){
    BinarySearchTreeNode *root = this -> root();
    inOrderTraverse(root);
}

void BinarySearchTree::inOrderTraverse(BinarySearchTreeNode *&root){
    if (!root) {
        return ;
    }
    inOrderTraverse(root -> left);
    print(root);
    inOrderTraverse(root -> right);
}

// PostOrder Traverse
void BinarySearchTree::postOrderTraverse(){
    BinarySearchTreeNode *root = this -> root();
    postOrderTraverse(root);
}

void BinarySearchTree::postOrderTraverse(BinarySearchTreeNode *&root){
    if (!root) {
        return ;
    }
    postOrderTraverse(root -> right);
    postOrderTraverse(root -> left);
    print(root);
}

// Level Traverse

void BinarySearchTree::levelTraverse(){
    BinarySearchTreeNode *root = this -> root();
    levelTraverse(root);
}

void BinarySearchTree::levelTraverse(BinarySearchTreeNode *&root){
    queue<BinarySearchTreeNode *> queue;
    
    if (root) {
        queue.push(root);
    }
    while (!queue.empty()) {
        BinarySearchTreeNode *node = queue.front();
        queue.pop();
        
        print(node);
        
        if (node -> left) {
            queue.push(node -> left);
        }
        if (node -> right) {
            queue.push(node -> right);
        }
    }
    return ;
}

int BinarySearchTree::countNodesInLevel(BinarySearchTreeNode *&root, int level){
    if (!root) {
        return 0;
    }
    if (level == 1) {
        return 1;
    }
    return countNodesInLevel(root -> left, level - 1) + countNodesInLevel(root -> right, level - 1);
}

#pragma mark - Count Leaf
void BinarySearchTree::countLeaf(){
    BinarySearchTreeNode *root = this -> root();
    cout << "Total Leaf are " << countLeaf(root) << endl;
}

int BinarySearchTree::countLeaf(BinarySearchTreeNode *&root){
    if (!root) {
        return 0;
    }
    if (!root -> left && !root -> right) {
        return 1;
    }
    return countLeaf(root -> left) + countLeaf(root -> right);
}

#pragma mark - Compare to the other tree

bool BinarySearchTree::isEqualTo(BinarySearchTree &otherTree){
    BinarySearchTreeNode *selfTreeRoot = this -> root();
    BinarySearchTreeNode *otherTreeRoot = otherTree.root();
    
    return compare(selfTreeRoot, otherTreeRoot);
}

bool BinarySearchTree::compare(BinarySearchTreeNode *&selfTreeRoot, BinarySearchTreeNode *&otherTreeRoot){
    if (!selfTreeRoot && !otherTreeRoot) {
        return true;
    }
    else if (!selfTreeRoot || !otherTreeRoot) {
        return false;
    }
    return compare(selfTreeRoot -> left, otherTreeRoot -> left) && compare(selfTreeRoot -> right, otherTreeRoot -> right);
}

#pragma mark - Is Balance

bool BinarySearchTree::isAVLTree(){
    BinarySearchTreeNode *root = this -> root();
    return isAVLTree(root);
}

bool BinarySearchTree::isAVLTree(BinarySearchTreeNode *&root){
    if (!root) {
        return true;
    }
    if (abs(depth(root -> left) - depth(root -> right)) <= 1) {
        cout << "Left minus right is "<< abs(depth(root -> left) - depth(root -> right)) << '\n';
        return isAVLTree(root -> left) && isAVLTree(root -> right);
    }
    return false;
}

#pragma mark - Tree's mirror

void BinarySearchTree::treesMirror(){
    BinarySearchTreeNode *root = this -> root();
    mirror(root);
}

BinarySearchTreeNode* BinarySearchTree::mirror(BinarySearchTreeNode *&root){
    if (!root) {
        return NULL;
    }
    BinarySearchTreeNode *temp = mirror(root -> left);
    
    root -> left = mirror(root -> right);
    root -> right = temp;
    
    return root;
}

#pragma mark - Search the previous ancestor

int BinarySearchTree::commonAncestor(const int& valueA, const int& valueB){
    BinarySearchTreeNode *root = this -> root();
    BinarySearchTreeNode *ancestorNode = commonAncestor(root, find(root, valueA), find(root, valueB));
    
    if (!ancestorNode) {
        cout << "No Common Ancestor!\n";
        return 0;
    }
    return ancestorNode -> value;
}

BinarySearchTreeNode* BinarySearchTree::commonAncestor(BinarySearchTreeNode *root, BinarySearchTreeNode *childA, BinarySearchTreeNode *childB){
    if (!root || !childA || !childB) {
        return NULL;
    }
    
    list<BinarySearchTreeNode *> childAPath;
    list<BinarySearchTreeNode *> childBPath;
    
    if (!getNodePath(root, childA, childAPath) || !getNodePath(root, childB, childBPath)) {
        return NULL;
    }

    list<BinarySearchTreeNode *>::iterator iterA(childAPath.begin()), iterB(childBPath.begin());
    
    BinarySearchTreeNode* ancestorNode = NULL;
    
    while (iterA != childAPath.end() && iterB != childBPath.end()) {
        if (*iterA == *iterB) {
            ancestorNode = *iterA;
        }
        else{
            break;
        }
        iterA++;
        iterB++;
    }
    
    return ancestorNode;
}

bool BinarySearchTree::getNodePath(BinarySearchTreeNode *&root, BinarySearchTreeNode *child, list<BinarySearchTreeNode *> &path){
    if (!root) {
        return false;
    }
    if (root == child) {
        path.push_back(root);
        return true;
    }
    path.push_back(root);
    bool found = false;
    
    found = getNodePath(root -> left, child, path);
    
    if (!found) {
        found = getNodePath(root -> right, child, path);
    }
    if (!found) {
        path.pop_back();
    }
    return found;
}

#pragma mark - Find Node

BinarySearchTreeNode* BinarySearchTree::find(const int& value){
    BinarySearchTreeNode *root = this -> root();
    return find(root, value);
}

BinarySearchTreeNode* BinarySearchTree::find(BinarySearchTreeNode *root, const int& value){
    if (!root) {
        return NULL;
    }
    else if (root -> value > value) {
        return find(root -> left, value);
    }
    else if (root -> value < value) {
        return find(root -> right, value);
    }
    else {
        return root;
    }
    return NULL;
}

#pragma mark - Farest Distance

int BinarySearchTree::farestDistance(){
    BinarySearchTreeNode *root = this -> root();
    return farestDistance(root);
}

int BinarySearchTree::farestDistance(BinarySearchTreeNode *root){
    if (!root) {
        return 0;
    }
    return depth(root -> left) + depth(root -> right);
}

#pragma mark - Rebuild Tree

BinarySearchTreeNode* BinarySearchTree::reBuildTreeThroughPreAndInOrder(int *preOrder, int *inOrder, int nodeNum){
    if (!preOrder || !inOrder || nodeNum <= 0) {
        return NULL;
    }
    
    BinarySearchTreeNode *root = new BinarySearchTreeNode(preOrder[0]);
    root -> left = NULL;
    root -> right = NULL;
    
    int rootPositionInOrder = -1;
    
    for (int i = 0; i < nodeNum; i++) {
        if (inOrder[i] == root -> value) {
            rootPositionInOrder = i;
            break;
        }
    }
    
    if (rootPositionInOrder == -1) {
        cout << "Invalid Order\n";
        return NULL;
    }
    
    int *leftPreOrder = preOrder + 1;
    int *leftInOrder = inOrder;
    root -> left = reBuildTreeThroughPreAndInOrder(leftPreOrder, leftInOrder, rootPositionInOrder);
    
    int *rightPreOrder = preOrder + rootPositionInOrder + 1;
    int *rightInOrder = inOrder + rootPositionInOrder + 1;
    root -> right = reBuildTreeThroughPreAndInOrder(rightPreOrder, rightInOrder, nodeNum - rootPositionInOrder -1);
    
    return root;
}

BinarySearchTreeNode* BinarySearchTree::rebuildTreeThroughInAndPostOrder(int *inOrder, int *postOrder, int nodeNum){
    if (!inOrder || !postOrder || nodeNum <= 0) {
        return NULL;
    }
    
    BinarySearchTreeNode *root = new BinarySearchTreeNode(postOrder[nodeNum - 1]);
    root -> left = NULL;
    root -> right = NULL;
    
    int rootPositionInOrder = -1;
    
    for (int i = 0; i < nodeNum; i++) {
        if (inOrder[i] == postOrder[nodeNum - 1]) {
            rootPositionInOrder = i;
            break;
        }
    }
    
    if (rootPositionInOrder == -1) {
        cout << "Invalid Order\n";
        return NULL;
    }
    
    
    int *leftInOrder = inOrder;
    int *leftPostOrder = postOrder + rootPositionInOrder;
    root -> left = rebuildTreeThroughInAndPostOrder(leftInOrder, leftPostOrder, rootPositionInOrder);
    
    int *rightInOrder = inOrder + rootPositionInOrder + 1;
    int *rightPostOrder = postOrder;
    root -> right = rebuildTreeThroughInAndPostOrder(rightInOrder, rightPostOrder, nodeNum - rootPositionInOrder - 1);
    
    return NULL;
}







