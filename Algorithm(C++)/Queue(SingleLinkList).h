//
//  Queue(SingleLinkList).h
//  Algorithm(C++)
//
//  Created by tang dixi on 17/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____Queue_SingleLinkList___
#define __Algorithm_C_____Queue_SingleLinkList___

#include <iostream>
#include "SingleLinkList.h"

template <class Type>
class Queue : public SingleLinkList<Type> {
public:
    /*  Construct Functions  */
    //
    explicit Queue<Type>();
    explicit Queue<Type>(const unsigned int& capacity);
    
    /*  Add Objects into the queue  */
    //
    void enQueue(const Type& object);
    
    /*  Remove the Object in the front  */
    //
    Type& deQueue();
    
    /*  Print the object in the node  */
    //
    void print(SingleLinkListNode<Type> *&node);
    
    /*  Traverse the Queue  */
    //
    void traverseQueue();
    
private:
    /*  Private Variables  */
    //
    SingleLinkListHeadNode<Type> *front_;
    SingleLinkListHeadNode<Type> *rear_;
    
    unsigned int capacity_;
    unsigned int size_;
};

#pragma mark - Construct Functions

template <class Type>
Queue<Type>::Queue(){
    if (!front_ && !rear_) {
        front_ = new SingleLinkListHeadNode<Type>();
        rear_ = new SingleLinkListHeadNode<Type>();
    }
    front_ -> next = NULL;
    rear_ -> next = NULL;
    capacity_ = 100;
    size_ = 0;
}

template <class Type>
Queue<Type>::Queue(const unsigned int& capacity){
    if (!front_ && !rear_) {
        front_ = new SingleLinkListHeadNode<Type>();
        rear_ = new SingleLinkListHeadNode<Type>();
    }
    front_ -> next = NULL;
    rear_ -> next = NULL;
    capacity_ = capacity;
    size_ = 0;
}

#pragma mark - Basic Functions

template <class Type>
void Queue<Type>::enQueue(const Type &object) {
    if (rear_ -> next == NULL) {
        SingleLinkListNode<Type> *node = new SingleLinkListNode<Type>(object);
        front_ -> next = node;
        rear_ -> next = node;
        size_++;
        return ;
    }
    else if (size_ == capacity_) {
        cout << "Full Queue!\n";
    }
    
    SingleLinkListNode<Type> *lastNode = rear_ -> next;
    SingleLinkListNode<Type> *node = new SingleLinkListNode<Type>(object);
    node -> next = lastNode -> next;
    lastNode -> next = node;
    rear_ -> next = node;
    size_++;
}

template <class Type>
Type& Queue<Type>::deQueue(){
    if (front_ -> next == NULL && rear_ -> next == NULL) {
        cout << "Empty Queue!\n";
        return 0;
    }
    
    SingleLinkListNode<Type> *currentNode = front_ -> next;
    Type object = currentNode -> value;
    front_ -> next = currentNode -> next;
    delete currentNode;
    size_--;
    
    return object;
}

#pragma mark - Print

template <class Type>
void Queue<Type>::print(SingleLinkListNode<Type> *&node){
    if (!node) {
        return ;
    }
    cout << node -> value;
}

#pragma mark - Traverse the Queue

template <class Type>
void Queue<Type>::traverseQueue() {
    if (front_ -> next == NULL && rear_ -> next == NULL) {
        cout << "Empty Queue";
        return ;
    }
    cout << "Front ";
    
    SingleLinkListNode<Type> *node = front_ -> next;
    
    while (node) {
        cout << " <- " << node -> value;
        node = node -> next;
    }
    
    cout << " <- Rear \n";
}

#endif /* defined(__Algorithm_C_____Queue_SingleLinkList___) */
