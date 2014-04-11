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

    vector<int> values;
    values.push_back(32);
    values.push_back(42);
    values.push_back(120);
    values.push_back(7);
    values.push_back(42);
    values.push_back(24);
    values.push_back(37);
    values.push_back(2);
    
    BinaryHeap<int> heap(values, MIN_HEAP);
    
//    heap.insertNode(32);
//    heap.insertNode(42);
//    heap.insertNode(120);
//    heap.insertNode(7);
//    heap.insertNode(42);
//    heap.insertNode(24);
//    heap.insertNode(37);
//    heap.insertNode(2);
    
    heap.traverseHeap();
    line();
    
}

void line(){
    cout << '\n';
}

