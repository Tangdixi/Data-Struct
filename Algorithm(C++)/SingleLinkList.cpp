//
//  SingleLinkList.cpp
//  Algorithm(C++)
//
//  Created by tang dixi on 28/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#include "SingleLinkList.h"

using namespace std;

SingleLinkList::SingleLinkList(){
    if (!this -> head_) {
        head_ = new SingleLinkListHeadNode();
    }
}

SingleLinkList::SingleLinkList(const int& value){
    if (!this -> head_) {
        head_ = new SingleLinkListHeadNode();
    }
    insertToHead(head_, value);
}

SingleLinkList::SingleLinkList(vector<int> values){
    if (!this -> head_) {
        head_ = new SingleLinkListHeadNode();
    }
//    vector<int>::iterator iter(values.begin());
    
}

SingleLinkListHeadNode* SingleLinkList::head() const{
    return this -> head_;
}

void SingleLinkList::print(SingleLinkListNode *&node){
    if (node) {
        cout  << node -> value << " -> ";
    }
}

#pragma mark Insert to List

void SingleLinkList::insertToHead(const int &value){
    SingleLinkListHeadNode *head = this -> head();
    insertToHead(head, value);
}

void SingleLinkList::insertToHead(SingleLinkListHeadNode *&head, const int &value){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode *node = new SingleLinkListNode(value);
    
    if (!node) {
        cout << "Node init failure\n";
        return ;
    }

    node -> next = head -> next;
    head -> next = node;
    
}

void SingleLinkList::insertToTail(const int &value){
    SingleLinkListHeadNode *head = this -> head();
    insertToTail(head, value);
}

void SingleLinkList::insertToTail(SingleLinkListHeadNode *&head, const int &value){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode *currentNode = head -> next;
    
    if (!currentNode) {
        currentNode = new SingleLinkListNode(value);
        return ;
    }
    
    while (currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    
    SingleLinkListNode *node = new SingleLinkListNode(value);
    node -> next = currentNode -> next;
    currentNode -> next = node;
    
}

void SingleLinkList::insertToIndex(const int &value, const int &index){
    SingleLinkListHeadNode *head = this -> head();
    insertToIndex(head, value, index);
}

void SingleLinkList::insertToIndex(SingleLinkListHeadNode *&head, const int &value, const int &index){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode *current = head -> next;
    
    for (int i = 0; i < index - 1; i++) {
        if (!current) {
            cout << "Out of limit\n";
            return ;
        }
        current = current -> next;
    }
    
    SingleLinkListNode *node = new SingleLinkListNode(value);
    
    node -> next = current -> next;
    current -> next = node;
    
}

#pragma mark - Traverse List

void SingleLinkList::traverseList(){
    SingleLinkListHeadNode *head = this -> head();
    traverseList(head);
}

void SingleLinkList::traverseList(SingleLinkListHeadNode *&head){
    if (!head) {
        return ;
    }
    
    SingleLinkListNode *circleEnterance = NULL;
    bool enterCircle = false;
    
    if (hasCircle(head)) {
        circleEnterance = findCircleEnterance(head);
    }
    
    cout << "Head -> ";
    
    SingleLinkListNode *node = head -> next;
    
    while (node) {
        if (node == circleEnterance && enterCircle) {
            break;
        }
        if (node == circleEnterance && !enterCircle) {
            enterCircle = true;
        }
        print(node);
        node = node -> next;
    }
    
    cout << " Tail\n";
}

#pragma mark - Has Circle

bool SingleLinkList::hasCircle(){
    SingleLinkListHeadNode *head = this -> head();
    if (!hasCircle(head)) {
        return false;
    }
    return true;
}

SingleLinkListNode* SingleLinkList::hasCircle(SingleLinkListHeadNode *&head){
    if (!head) {
        return NULL;
    }
    
    SingleLinkListNode *fastPointer = head -> next;
    SingleLinkListNode *slowPointer = head -> next;
    
    while (fastPointer && slowPointer) {
        fastPointer = fastPointer -> next -> next;
        slowPointer = slowPointer -> next;
        if (fastPointer == slowPointer) {
            return slowPointer;
        }
    }
    return NULL;
}

#pragma mark - Find Node

SingleLinkListNode* SingleLinkList::findNode(const int &value){
    SingleLinkListHeadNode *head = this -> head();
    return findNode(head, value);
}

SingleLinkListNode* SingleLinkList::findNode(SingleLinkListHeadNode *&head, const int& value){
    if (!head) {
        return NULL;
    }
    
    SingleLinkListNode *currentNode = head -> next;
    
    while (currentNode -> value != value && currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    return currentNode;
}

#pragma mark -create ciecle

void SingleLinkList::createCircleToNode(const int &value){
    SingleLinkListHeadNode *head = this -> head();
    createCircleToNode(head, value);
}

void SingleLinkList::createCircleToNode(SingleLinkListHeadNode *&head, const int &value){
    if (!head) {
        return ;
    }
    SingleLinkListNode *currentNode = head -> next;
    
    if (!currentNode) {
        return ;
    }
    
    while (currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    
    SingleLinkListNode *targetNode = findNode(value);
    currentNode -> next = targetNode;
}

#pragma mark - Find the enterance of circle

void SingleLinkList::findCircleEnterance(){
    SingleLinkListHeadNode *head = this -> head();
    cout << "The circle enterance is " << findCircleEnterance(head) -> value << '\n';
}

SingleLinkListNode* SingleLinkList::findCircleEnterance(SingleLinkListHeadNode *&head){
    SingleLinkListNode *slowPointer = hasCircle(head);
    if (!slowPointer) {
        cout << "Has no Circle!\n";
        return NULL;
    }
    
    SingleLinkListNode *fakeTail = slowPointer;
    
    SingleLinkListNode *firstTempListHead = head -> next;
    SingleLinkListNode *secondTempListHead = slowPointer -> next;
    
    return crossNode(firstTempListHead, secondTempListHead, fakeTail);
}

#pragma mark - Cross to List

SingleLinkListNode* SingleLinkList::crossNode(SingleLinkListNode *&headInFirst, SingleLinkListNode *&headInSecond, SingleLinkListNode *&tailNode){
    if (!headInFirst || !headInSecond) {
        return NULL;
    }
    
    int firstListLength = 0;
    int secondListLength = 0;
    
    SingleLinkListNode *firstHead = headInFirst;
    SingleLinkListNode *secondHead = headInSecond;
    SingleLinkListNode *tempFirstHead = firstHead;
    SingleLinkListNode *tempSecondHead = secondHead;
    
    while (tempFirstHead != tailNode) {
        tempFirstHead = tempFirstHead -> next;
        firstListLength++;
    }
    
    while (tempSecondHead != tailNode) {
        tempSecondHead = tempSecondHead -> next;
        secondListLength++;
    }
    
    if (tempFirstHead != tempSecondHead) {
        return NULL;
    }
    
    int offSet = firstListLength - secondListLength;
    
    if (offSet > 0) {
        while (offSet--) {
            firstHead = firstHead -> next;
        }
    }
    else {
        while (offSet--) {
            secondHead = secondHead -> next;
        }
    }
    while (firstHead != secondHead) {
        firstHead = firstHead -> next;
        secondHead = secondHead -> next;
    }
    return firstHead;
}




