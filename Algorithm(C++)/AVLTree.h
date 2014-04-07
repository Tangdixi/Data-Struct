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

    /*  Configure the tree's height  */
    //
    void configureHeight();
    
    /*  Delete a node if it exist in the AVLTree  */
    //
    void deleteNode(const Type& value);
    
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
    
    /*  Count leaf in a BSTree  */
    //
    void countLeaf();

private:
    BinarySearchTreeNode<Type> *root_;
};

#pragma mark - Construct Function

template <class Type>
AVLTree<Type>::AVLTree(){
    if (!root_) {
        root_ = new BinarySearchTreeNode<Type>();
    }
}

template <class Type>
AVLTree<Type>::AVLTree(const Type& value){
    if (!root_) {
        root_ = new BinarySearchTreeNode<Type>(value);
    }
}

#pragma mark - Insert Node to AVLTree

template <class Type>
void AVLTree<Type>::insertNode(const Type &value){
    BinarySearchTree<Type>::insertNode(root_, value);
}

template <class Type>
void AVLTree<Type>::insertNode(vector<Type> &values){
    BinarySearchTree<Type>::insertNode(root_, values);
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

#pragma mark - Count Leaf 

template <class Type>
void AVLTree<Type>::countLeaf(){
    BinarySearchTree<Type>::countLeaf(root_);
}

#endif /* defined(__Algorithm_C_____AVLTree__) */
