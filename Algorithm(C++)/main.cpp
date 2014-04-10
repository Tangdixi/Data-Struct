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
#include "BinaryHeap.h"

using namespace std;

void line();

int main(int argc, const char * argv[])
{

    BinaryHeap<int> heap(100, MAX_HEAP);
    
    heap.insertNode(10);
    heap.insertNode(20);
    heap.insertNode(5);
    heap.insertNode(2);
    heap.insertNode(50);
    
    heap.traverseHeap();
    line();
    
    cout << heap.isLeaf(3);
    line();
}

void line(){
    cout << '\n';
}

