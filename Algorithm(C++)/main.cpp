//
//  main.cpp
//  Algorithm(C++)
//
//  Created by tang dixi on 17/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#include <iostream>
#include <vector>

#include "BinarySearchTree.h"
#include "SingleLinkList.h"
#include "Stack.h"
#include "DoubleLinkList.h"
#include "AVLTree.h"

using namespace std;

int preOrder[] = {20,10, 8, 15, 27, 25, 30};
int inOrder[] = {8, 10, 15, 20, 25, 27, 30};
int postOrder[] = {30, 25, 27, 15, 8, 10, 20};

void line();

int main(int argc, const char * argv[])
{
//    AVLTree<int> avlTree;
//    
//    avlTree.insertNode(30);
//    avlTree.insertNode(15);
//    avlTree.insertNode(60);
//    avlTree.insertNode(10);
//    avlTree.insertNode(20);
//    avlTree.insertNode(40);
//    avlTree.insertNode(70);
//    avlTree.insertNode(13);
//    avlTree.insertNode(35);
//    avlTree.insertNode(50);
//    avlTree.insertNode(80);
//    avlTree.insertNode(45);
//    avlTree.insertNode(55);
//    
//    avlTree.inOrderTraverse();
//    line();
//    
//    avlTree.deleteNode(15);
//    
//    avlTree.inOrderTraverse();
//    line();
    
    BinarySearchTree<int> tree;
    
    tree.insertNode(30);
    tree.insertNode(15);
    tree.insertNode(60);
    tree.insertNode(10);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(70);
    tree.insertNode(13);
    tree.insertNode(35);
    tree.insertNode(50);
    tree.insertNode(80);
    tree.insertNode(45);
    tree.insertNode(55);

    tree.inOrderTraverse();
    line();
    
    tree.deleteNode(15);
    
    tree.inOrderTraverse();
    line();
}

void line(){
    cout << '\n';
}

