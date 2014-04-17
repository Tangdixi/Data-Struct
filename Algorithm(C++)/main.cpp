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
//#include "Stack(SingleLinkList).h"
#include "Stack(Vector).h"
#include "DoubleLinkList.h"
#include "AVLTree.h"
#include "BinaryHeap.h"

using namespace std;

void line();

int main(int argc, const char * argv[])
{
    Stack<int> stack(10);
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.traverseStack();
    
    stack.removeAllObjects();

    line();
    stack.traverseStack();
    line();
}

void line(){
    cout << '\n';
}


