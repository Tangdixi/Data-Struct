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
    AVLTree<int> avlTree(10);
    avlTree.insertNode(20);
    avlTree.insertNode(5);
    avlTree.insertNode(4);
    
    avlTree.configureHeight();
    
    avlTree.preOrderTraverse();
}

void line(){
    cout << '\n';
}

