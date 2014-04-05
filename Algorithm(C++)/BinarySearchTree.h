//
//  BinarySearchTree.h
//  Algorithm(C++)
//
//  Created by tang dixi on 30/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____BinarySearchTree__
#define __Algorithm_C_____BinarySearchTree__

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <list>
#include <cstring>

template<typename Type>
struct BinarySearchTreeNode{
    BinarySearchTreeNode()
    :value(0), left(NULL), right(NULL){};
    
    BinarySearchTreeNode(const int& value_)
    :value(value_), left(NULL), right(NULL){}
    
    Type value;
    BinarySearchTreeNode<Type> *left;
    BinarySearchTreeNode<Type> *right;
};

using namespace std;

template <class Type>
class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(Type value);
    BinarySearchTree(vector<Type> values);
    BinarySearchTree(BinarySearchTree<Type>& otherTree);
    BinarySearchTree(int *preOrder, int *inOrder, const unsigned int& length, const unsigned int& type);
    
    BinarySearchTreeNode<Type>* root() const;
    bool contains(Type value);
    bool contains(BinarySearchTreeNode<Type> *root, Type value);
    
    void insertNode(vector<Type> values);
    void insertNode(Type value);
    void insertNode(BinarySearchTreeNode<Type> *&root, Type value);
    void print(BinarySearchTreeNode<Type> *&currentNode);
    
    void deleteNode(Type value);
    void deleteNode(Type value, BinarySearchTreeNode<Type> *&root);
    
    void findMin();
    BinarySearchTreeNode<Type>* findMin(BinarySearchTreeNode<Type> *&root);
    
    void findMax();
    BinarySearchTreeNode<Type>* findMax(BinarySearchTreeNode<Type> *&root);
    
    void preOrderTraverse();
    void preOrderTraverse(BinarySearchTreeNode<Type> *&root);
    
    void inOrderTraverse();
    void inOrderTraverse(BinarySearchTreeNode<Type> *&root);
    
    void postOrderTraverse();
    void postOrderTraverse(BinarySearchTreeNode<Type> *&root);
    
    void levelTraverse();
    void levelTraverse(BinarySearchTreeNode<Type> *&root);
    
    unsigned int countNodesInLevel(BinarySearchTreeNode<Type> *&root, int level);
    
    void countLeaf();
    unsigned int countLeaf(BinarySearchTreeNode<Type> *&root);
    
    bool isEqualTo(BinarySearchTree<Type> &otherTree);
    bool compare(BinarySearchTreeNode<Type> *&selfTreeRoot, BinarySearchTreeNode<Type> *&otherTreeRoot);
    
    unsigned int depth();
    unsigned int depth(BinarySearchTreeNode<Type> *&root);
    
    bool isAVLTree();
    bool isAVLTree(BinarySearchTreeNode<Type> *&root);
    
    void treesMirror();
    BinarySearchTreeNode<Type>* mirror(BinarySearchTreeNode<Type> *&root);
    
    BinarySearchTreeNode<Type>* find(Type value);
    BinarySearchTreeNode<Type>* find(BinarySearchTreeNode<Type> *root, Type value);
    
    Type commonAncestor(Type valueA, Type valueB);
    BinarySearchTreeNode<Type>* commonAncestor(BinarySearchTreeNode<Type> *root, BinarySearchTreeNode<Type> *childA, BinarySearchTreeNode<Type> *childB);
    bool getNodePath(BinarySearchTreeNode<Type> *&root, BinarySearchTreeNode<Type> *child, list<BinarySearchTreeNode<Type> *> &path);
    
    unsigned int farestDistance();
    unsigned int farestDistance(BinarySearchTreeNode<Type> *root);
    
    BinarySearchTreeNode<Type>* reBuildTreeThroughPreAndInOrder(int *preOrder, int *inOrder, int nodeNum);
    BinarySearchTreeNode<Type>* rebuildTreeThroughInAndPostOrder(int *inOrder, int *postOrder, int nodeNum);
    
    // Over load operator
    BinarySearchTree<Type> &operator=(BinarySearchTree<Type> const& otherTree);
    
private:
    BinarySearchTreeNode<Type> *root_;
};

#pragma mark - Construct Function

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(){
    if (!root_) {
        root_ = new BinarySearchTreeNode<Type>();
    }
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(Type value){
    if (root_) {
        root_ = new BinarySearchTreeNode<Type>(value);
    }
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(vector<Type> values){
    if (!this -> root_) {
        vector<int>::iterator iter(values.begin());
        root_ = new BinarySearchTreeNode<Type>(*iter);
        
        while (iter != values.end()) {
            if (iter != values.begin()) {
                this -> insertNode(*iter);
            }
            iter++;
        }
    }
}

template <class Type>
BinarySearchTree<Type>::BinarySearchTree(int *preOrder, int *inOrder, const unsigned int& length, const unsigned int& type){
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

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::root() const{
    return this -> root_;
}

#pragma mark - Basic Function

template <class Type>
unsigned int BinarySearchTree<Type>::depth(){
    BinarySearchTreeNode<Type> *root = this -> root();
    return depth(root);
}

template <class Type>
unsigned int BinarySearchTree<Type>::depth(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return 0;
    }
    return depth(root -> left) >= depth(root -> right) ? (depth(root -> left) + 1) : (depth(root -> right) + 1);
}

template <class Type>
bool BinarySearchTree<Type>::contains(Type value){
    BinarySearchTreeNode<Type>* root = this -> root();
    return contains(root, value);
}

template <class Type>
bool BinarySearchTree<Type>::contains(BinarySearchTreeNode<Type> *node, Type value){
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

#pragma mark - Delete node

template <class Type>
void BinarySearchTree<Type>::deleteNode(Type value){
    BinarySearchTreeNode<Type> *root = this -> root();
    if (find(value)) {
        deleteNode(value, root);
    }
}

template <class Type>
void BinarySearchTree<Type>::deleteNode(Type value, BinarySearchTreeNode<Type> *&root){
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
        BinarySearchTreeNode<Type> *temp = root;
        root = (root -> left ? root -> left : root -> right);
        delete temp;
    }
}

#pragma mark - Find Max or Min Node

template <class Type>
void BinarySearchTree<Type>::findMin(){
    BinarySearchTreeNode<Type> *root = this -> root();
    findMin(root);
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::findMin(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return NULL;
    }
    return findMin(root -> left);
}

template <class Type>
void BinarySearchTree<Type>::findMax(){
    BinarySearchTreeNode<Type> *root = this -> root();
    findMax(root);
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::findMax(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return NULL;
    }
    return findMin(root -> right);
}

#pragma mark - Insert function

template <class Type>
void BinarySearchTree<Type>::insertNode(vector<Type> values){
    for (vector<int>::iterator iter(values.begin()); iter != values.end(); iter++) {
        insertNode(*iter);
    }
}

template <class Type>
void BinarySearchTree<Type>::insertNode(BinarySearchTreeNode<Type> *&root, Type value){
    if (!root) {
        root = new BinarySearchTreeNode<Type>(value);
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

template <class Type>
void BinarySearchTree<Type>::insertNode(Type value){
    BinarySearchTreeNode<Type> *root = this -> root();
    insertNode(root, value);
}

#pragma mark - Print tree

template <class Type>
void BinarySearchTree<Type>::print(BinarySearchTreeNode<Type> *&currentNode){
    cout << currentNode -> value << ' ';
}

#pragma mark - Traverse tree

// PreOrder Traverse
template <class Type>
void BinarySearchTree<Type>::preOrderTraverse(){
    BinarySearchTreeNode<Type> *root = this -> root();
    preOrderTraverse(root);
}

template <class Type>
void BinarySearchTree<Type>::preOrderTraverse(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return ;
    }
    print(root);
    preOrderTraverse(root -> left);
    preOrderTraverse(root -> right);
}

// InOrder Traverse
template <class Type>
void BinarySearchTree<Type>::inOrderTraverse(){
    BinarySearchTreeNode<Type> *root = this -> root();
    inOrderTraverse(root);
}

template <class Type>
void BinarySearchTree<Type>::inOrderTraverse(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return ;
    }
    inOrderTraverse(root -> left);
    print(root);
    inOrderTraverse(root -> right);
}

// PostOrder Traverse
template <class Type>
void BinarySearchTree<Type>::postOrderTraverse(){
    BinarySearchTreeNode<Type> *root = this -> root();
    postOrderTraverse(root);
}

template <class Type>
void BinarySearchTree<Type>::postOrderTraverse(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return ;
    }
    postOrderTraverse(root -> right);
    postOrderTraverse(root -> left);
    print(root);
}

// Level Traverse
template <class Type>
void BinarySearchTree<Type>::levelTraverse(){
    BinarySearchTreeNode<Type> *root = this -> root();
    levelTraverse(root);
}

template <class Type>
void BinarySearchTree<Type>::levelTraverse(BinarySearchTreeNode<Type> *&root){
    queue<BinarySearchTreeNode<Type> *> queue;
    
    if (root) {
        queue.push(root);
    }
    while (!queue.empty()) {
        BinarySearchTreeNode<Type> *node = queue.front();
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

template <class Type>
unsigned int BinarySearchTree<Type>::countNodesInLevel(BinarySearchTreeNode<Type> *&root, int level){
    if (!root) {
        return 0;
    }
    if (level == 1) {
        return 1;
    }
    return countNodesInLevel(root -> left, level - 1) + countNodesInLevel(root -> right, level - 1);
}

#pragma mark - Count Leaf
template <class Type>
void BinarySearchTree<Type>::countLeaf(){
    BinarySearchTreeNode<Type> *root = this -> root();
    cout << "Total Leaf are " << countLeaf(root) << endl;
}

template <class Type>
int BinarySearchTree<Type>::countLeaf(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return 0;
    }
    if (!root -> left && !root -> right) {
        return 1;
    }
    return countLeaf(root -> left) + countLeaf(root -> right);
}

#pragma mark - Compare to the other tree

template <class Type>
bool BinarySearchTree<Type>::isEqualTo(BinarySearchTree<Type> &otherTree){
    BinarySearchTreeNode<Type> *selfTreeRoot = this -> root();
    BinarySearchTreeNode<Type> *otherTreeRoot = otherTree.root();
    
    return compare(selfTreeRoot, otherTreeRoot);
}

template <class Type>
bool BinarySearchTree<Type>::compare(BinarySearchTreeNode<Type> *&selfTreeRoot, BinarySearchTreeNode<Type> *&otherTreeRoot){
    if (!selfTreeRoot && !otherTreeRoot) {
        return true;
    }
    else if (!selfTreeRoot || !otherTreeRoot) {
        return false;
    }
    return compare(selfTreeRoot -> left, otherTreeRoot -> left) && compare(selfTreeRoot -> right, otherTreeRoot -> right);
}

#pragma mark - Is Balance

template <class Type>
bool BinarySearchTree<Type>::isAVLTree(){
    BinarySearchTreeNode<Type> *root = this -> root();
    return isAVLTree(root);
}

template <class Type>
bool BinarySearchTree<Type>::isAVLTree(BinarySearchTreeNode<Type> *&root){
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

template <class Type>
void BinarySearchTree<Type>::treesMirror(){
    BinarySearchTreeNode<Type> *root = this -> root();
    mirror(root);
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::mirror(BinarySearchTreeNode<Type> *&root){
    if (!root) {
        return NULL;
    }
    BinarySearchTreeNode<Type> *temp = mirror(root -> left);
    
    root -> left = mirror(root -> right);
    root -> right = temp;
    
    return root;
}

#pragma mark - Search the previous ancestor
template <class Type>
Type BinarySearchTree<Type>::commonAncestor(Type valueA, Type valueB){
    BinarySearchTreeNode<Type> *root = this -> root();
    BinarySearchTreeNode<Type> *ancestorNode = commonAncestor(root, find(root, valueA), find(root, valueB));
    
    if (!ancestorNode) {
        cout << "No Common Ancestor!\n";
        return 0;
    }
    return ancestorNode -> value;
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::commonAncestor(BinarySearchTreeNode<Type> *root, BinarySearchTreeNode<Type> *childA, BinarySearchTreeNode<Type> *childB){
    if (!root || !childA || !childB) {
        return NULL;
    }
    
    list<BinarySearchTreeNode<Type> *> childAPath;
    list<BinarySearchTreeNode<Type> *> childBPath;
    
    if (!getNodePath(root, childA, childAPath) || !getNodePath(root, childB, childBPath)) {
        return NULL;
    }
    
    typename list< BinarySearchTreeNode<Type> *>::iterator iterA(childAPath.begin()), iterB(childBPath.begin());
    
    BinarySearchTreeNode<Type>* ancestorNode = NULL;
    
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

template <class Type>
bool BinarySearchTree<Type>::getNodePath(BinarySearchTreeNode<Type> *&root, BinarySearchTreeNode<Type> *child, list<BinarySearchTreeNode<Type> *> &path){
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

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::find(Type value){
    BinarySearchTreeNode<Type> *root = this -> root();
    return find(root, value);
}

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::find(BinarySearchTreeNode<Type> *root, Type value){
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

template <class Type>
unsigned int BinarySearchTree<Type>::farestDistance(){
    BinarySearchTreeNode<Type> *root = this -> root();
    return farestDistance(root);
}

template <class Type>
unsigned int BinarySearchTree<Type>::farestDistance(BinarySearchTreeNode<Type> *root){
    if (!root) {
        return 0;
    }
    return depth(root -> left) + depth(root -> right);
}

#pragma mark - Rebuild Tree

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::reBuildTreeThroughPreAndInOrder(int *preOrder, int *inOrder, int nodeNum){
    if (!preOrder || !inOrder || nodeNum <= 0) {
        return NULL;
    }
    
    BinarySearchTreeNode<Type> *root = new BinarySearchTreeNode<Type>(preOrder[0]);
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

template <class Type>
BinarySearchTreeNode<Type>* BinarySearchTree<Type>::rebuildTreeThroughInAndPostOrder(int *inOrder, int *postOrder, int nodeNum){
    if (!inOrder || !postOrder || nodeNum <= 0) {
        return NULL;
    }
    
    BinarySearchTreeNode<Type> *root = new BinarySearchTreeNode<Type>(postOrder[nodeNum - 1]);
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

#endif /* defined(__Algorithm_C_____BinarySearchTree__) */
