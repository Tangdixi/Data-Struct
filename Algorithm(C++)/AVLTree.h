//
//  AVLTree.h
//  Algorithm(C++)
//
//  Created by tang dixi on 6/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____AVLTree__
#define __Algorithm_C_____AVLTree__

#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

template <class Type>
class AVLTree : public BinarySearchTree<Type> {
public:
    AVLTree();
    AVLTree(const Type& value);
    
    /*  Judge does the AVLTree has the target node  */
    //
    bool contains(const Type& value);
    
    /*  Insert a set of nodes into AVLTree  */
    //
    void insertNode(vector<Type>& values);
    
    /*  Insert a new node into AVLTree  */
    //
    void insertNode(const Type& value);

    /*  Delete a node in the AVLTree  */
    //
    void deleteNode(const Type& value);
    
    /*  Configure the tree's height  */
    //
    void configureHeight();
    
    /*  Traverse the AVLTree in Pre Order  */
    //
    void preOrderTraverse();
    
    /*  Traverse the AVLTree in In Order  */
    //
    void inOrderTraverse();
    
    /*  Traverse the AVLTree in Post Order  */
    //
    void postOrderTraverse();
    
    /*  Traverse the AVLTree in Level Order  */
    //
    void levelTraverse();
    
    /*  Count the node in the level of the AVLTree  */
    //
    unsigned int countNodesInLevel(BinarySearchTreeNode<Type> *&root, unsigned int level);

    /*  The current node's height  */
    //
    unsigned int height(BinarySearchTreeNode<Type> *&root) const;
    
    /*  The larger height between nodeA and nodeB  */
    //
    unsigned int maxHeightBetween(unsigned int nodeAHeight, unsigned int nodeBHeight) const;
    
private:
    /*  Private Variable  */
    //
    BinarySearchTreeNode<Type> *root_;
    
protected:
    /*  Protected Functions  */
    //
    void insertNode(BinarySearchTreeNode<Type> *&root, const Type& value);
    void deleteNode(BinarySearchTreeNode<Type> *&root, const Type& value);
    
    void leftRotation(BinarySearchTreeNode<Type> *&root);
    void rightRotation(BinarySearchTreeNode<Type> *&root);
    void leftRightRotation(BinarySearchTreeNode<Type> *&root);
    void rightLeftRotation(BinarySearchTreeNode<Type> *&root);
};

#pragma mark - Construct Function

template <class Type>
AVLTree<Type>::AVLTree(){
}

template <class Type>
AVLTree<Type>::AVLTree(const Type& value){
    if (!root_) {
        root_ = new BinarySearchTreeNode<Type>(value);
    }
}

#pragma mark - The height of the AVLTree

template <class Type>
unsigned int AVLTree<Type>::height(BinarySearchTreeNode<Type> *&root) const{
    return BinarySearchTree<Type>::height(root);
}

template <class Type>
unsigned int AVLTree<Type>::maxHeightBetween(unsigned int nodeAHeight, unsigned int nodeBHeight) const{
    return BinarySearchTree<Type>::maxHeightBetween(nodeAHeight, nodeBHeight);
}

#pragma mark - Insert Node to AVLTree

template <class Type>
void AVLTree<Type>::insertNode(BinarySearchTreeNode<Type> *&root, const Type &value){
    if (!root) {
        root = new BinarySearchTreeNode<Type>(value);
    }
    else if (root -> value > value){
        insertNode(root -> left, value);
        if (height(root -> left) - height(root -> right) == 2) {
            if (root -> left -> value > value) {
                leftRotation(root);
            }
            else {
                leftRightRotation(root);
            }
        }
    }
    else if (root -> value < value){
        insertNode(root -> right, value);
        if (height(root -> right) - height(root -> left) == 2) {
            if (root -> right -> value < value) {
                rightRotation(root);
            }
            else {
                rightLeftRotation(root);
            }
        }
    }
    else {
        return ;
    }
    root -> height = maxHeightBetween(height(root -> left), height(root -> right)) + 1;
}

template <class Type>
void AVLTree<Type>::insertNode(const Type &value){
    if (!root_) {
        root_ = new BinarySearchTreeNode<Type>(value);
        return ;
    }
    insertNode(root_, value);
}

template <class Type>
void AVLTree<Type>::insertNode(vector<Type> &values){
    for (typename vector<Type>::iterator iter(values.begin()); iter != values.end(); iter++) {
        if (!root_) {
            root_ = new BinarySearchTreeNode<Type>(*iter);
            continue;
        }
        insertNode(*iter);
    }
}

#pragma mark - Delete node from AVLTree

template <class Type>
void AVLTree<Type>::deleteNode(const Type &value){
    deleteNode(root_, value);
}

template <class Type>
void AVLTree<Type>::deleteNode(BinarySearchTreeNode<Type> *&root, const Type &value){
    if (!root) {
        return ;
    }
    else if (root -> value > value) {
        deleteNode(root -> left, value);
        if (height(root -> right) - height(root -> left) > 2) {
            if (root -> right -> left && height(root -> right -> left) > height(root -> left -> right)) {
                rightLeftRotation(root);
            }
            else {
                rightRotation(root);
            }
        }
    }
    else if (root -> value < value) {
        deleteNode(root -> right, value);
        if (height(root -> left) - height(root -> right) == 2) {
            if (root -> left -> right && height(root -> left -> right) > height(root -> left -> left)) {
                leftRightRotation(root);
            }
            else {
                leftRotation(root);
            }
        }
    }
    else {
        if (root -> left && root -> right) {
            BinarySearchTreeNode<Type> *temp = root -> right;
            temp = BinarySearchTree<Type>::findMin(temp);
            root -> value = temp -> value;
            
            deleteNode(root -> right, temp -> value);
            
            if (height(root -> left) - height(root -> right) == 2) {
                if (root -> left -> right && height(root -> left -> right) > height(root -> left -> left)) {
                    leftRightRotation(root);
                }
                else {
                    leftRotation(root);
                }
            }
        }
        else {
            if (root -> left) {
                BinarySearchTreeNode<Type> *currentNode = root;
                root = root -> left;
                delete currentNode;
            }
            else if (root -> right) {
                BinarySearchTreeNode<Type> *currentNode = root;
                root = root -> right;
                delete currentNode;
            }
            else {
                delete root;
                root = NULL;
                return ;
            }
        }
    }
    root -> height = maxHeightBetween(height(root -> left), height(root -> right)) + 1;
}

#pragma mark - Rotation

template <class Type>
void AVLTree<Type>::leftRotation(BinarySearchTreeNode<Type> *&root){
    BinarySearchTreeNode<Type> *leftNode = root -> left;
    root -> left = leftNode -> right;
    leftNode -> right = root;
    
    root -> height = maxHeightBetween(height(root -> left), height(root -> right)) + 1;
    leftNode -> height = maxHeightBetween(height(leftNode -> left), height(root)) + 1;
    
    root = leftNode;
}

template <class Type>
void AVLTree<Type>::rightRotation(BinarySearchTreeNode<Type> *&root){
    BinarySearchTreeNode<Type> *rightNode = root -> right;
    root -> right = rightNode -> left;
    rightNode -> left = root;
    
    root -> height = maxHeightBetween(height(root -> left), height(root -> right)) + 1;
    rightNode -> height = maxHeightBetween(height(rightNode -> right), height(root)) + 1;
    
    root = rightNode;
}

template <class Type>
void AVLTree<Type>::leftRightRotation(BinarySearchTreeNode<Type> *&root){
    rightRotation(root -> left);
    leftRotation(root);
}

template <class Type>
void AVLTree<Type>::rightLeftRotation(BinarySearchTreeNode<Type> *&root){
    leftRotation(root -> right);
    rightRotation(root);
}

#pragma mark - Traverse the AVLTree in PreOrder

template <class Type>
void AVLTree<Type>::preOrderTraverse(){
    BinarySearchTree<Type>::preOrderTraverse(root_);
}

template <class Type>
void AVLTree<Type>::inOrderTraverse(){
    BinarySearchTree<Type>::inOrderTraverse(root_);
}

template <class Type>
void AVLTree<Type>::postOrderTraverse(){
    BinarySearchTree<Type>::postOrderTraverse(root_);
}

template <class Type>
void AVLTree<Type>::levelTraverse(){
    BinarySearchTree<Type>::levelTraverse(root_);
}

#endif /* defined(__Algorithm_C_____AVLTree__) */
