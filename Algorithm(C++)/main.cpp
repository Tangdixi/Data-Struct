//
//  main.cpp
//  Algorithm(C++)
//
//  Created by tang dixi on 17/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#include <iostream>
#include "BinarySearchTree.h"
#include "SingleLinkList.h"

using namespace std;

int preOrder[] = {20,10, 8, 15, 27, 25, 30};
int inOrder[] = {8, 10, 15, 20, 25, 27, 30};
int postOrder[] = {30, 25, 27, 15, 8, 10, 20};

void line();

int main(int argc, const char * argv[])
{
    SingleLinkList list;
    
    list.insertToHead(10);
    list.insertToHead(20);
    list.insertToHead(30);
    list.insertToHead(40);
    list.insertToHead(50);
    list.insertToHead(60);
    list.insertToHead(70);
    list.insertToHead(80);
    
    list.createCircleToNode(40);
    
    list.findCircleEnterance();
    list.traverseList();
}

void line(){
    cout << '\n';
}

