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

struct BinarySearchTreeNode{
    BinarySearchTreeNode()
    :value(0), left(NULL), right(NULL){};
    
    BinarySearchTreeNode(const int& value_)
    :value(value_), left(NULL), right(NULL){}
    
    int value;
    BinarySearchTreeNode *left;
    BinarySearchTreeNode *right;
};

using namespace std;

class BinarySearchTree{
public:
    BinarySearchTree();
    BinarySearchTree(const int& value);
    BinarySearchTree(vector<int> values);
    BinarySearchTree(BinarySearchTree& otherTree);
    BinarySearchTree(int *preOrder, int *inOrder, const int& length, const int& type);
    
    BinarySearchTreeNode* root() const;
    bool contains(const int& value);
    bool contains(BinarySearchTreeNode *root, const int& value);
    
    void insertNode(vector<int> values);
    void insertNode(const int& value);
    void insertNode(BinarySearchTreeNode *&root, const int& value);
    void print(BinarySearchTreeNode *&currentNode);
    
    void deleteNode(const int& value);
    void deleteNode(const int& value, BinarySearchTreeNode *&root);
    
    void findMin();
    BinarySearchTreeNode* findMin(BinarySearchTreeNode *&root);
    
    void findMax();
    BinarySearchTreeNode* findMax(BinarySearchTreeNode *&root);
    
    void preOrderTraverse();
    void preOrderTraverse(BinarySearchTreeNode *&root);
    
    void inOrderTraverse();
    void inOrderTraverse(BinarySearchTreeNode *&root);
    
    void postOrderTraverse();
    void postOrderTraverse(BinarySearchTreeNode *&root);
    
    void levelTraverse();
    void levelTraverse(BinarySearchTreeNode *&root);
    
    int countNodesInLevel(BinarySearchTreeNode *&root, int level);
    
    void countLeaf();
    int countLeaf(BinarySearchTreeNode *&root);
    
    bool isEqualTo(BinarySearchTree &otherTree);
    bool compare(BinarySearchTreeNode *&selfTreeRoot, BinarySearchTreeNode *&otherTreeRoot);
    
    int depth();
    int depth(BinarySearchTreeNode *&root);
    
    bool isAVLTree();
    bool isAVLTree(BinarySearchTreeNode *&root);
    
    void treesMirror();
    BinarySearchTreeNode* mirror(BinarySearchTreeNode *&root);
    
    BinarySearchTreeNode* find(const int& value);
    BinarySearchTreeNode* find(BinarySearchTreeNode *root, const int& value);
    
    int commonAncestor(const int& valueA, const int& valueB);
    BinarySearchTreeNode* commonAncestor(BinarySearchTreeNode *root, BinarySearchTreeNode *childA, BinarySearchTreeNode *childB);
    bool getNodePath(BinarySearchTreeNode *&root, BinarySearchTreeNode *child, list<BinarySearchTreeNode *> &path);
    
    int farestDistance();
    int farestDistance(BinarySearchTreeNode *root);
    
    BinarySearchTreeNode* reBuildTreeThroughPreAndInOrder(int *preOrder, int *inOrder, int nodeNum);
    BinarySearchTreeNode* rebuildTreeThroughInAndPostOrder(int *inOrder, int *postOrder, int nodeNum);
    
    // Over load operator
    BinarySearchTree &operator=(BinarySearchTree const& otherTree);
    
    
private:
    BinarySearchTreeNode *root_;
};

#endif /* defined(__Algorithm_C_____BinarySearchTree__) */
