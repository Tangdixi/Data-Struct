//
//  Stack.h
//  Algorithm(C++)
//
//  Created by tang dixi on 3/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____Stack__
#define __Algorithm_C_____Stack__

#include <iostream>
#include "SingleLinkList.h"

template <class Type>
class Stack : public SingleLinkList<Type>{
public:
    
    /*  Construct Function  */
    //
    explicit Stack<Type>();
    explicit Stack<Type>(const unsigned int& capacity);
    
    /*  Push the element into the stack  */
    //
    void push(const Type& value);
    
    /*  Pop the element from the stack  */
    //
    Type pop();
    
    /*  Count the elements in the stack  */
    //
    unsigned int size() const;
    
    /*  Return the top element in the stack  */
    //
    SingleLinkListNode<Type>* top();
    
    /*  Traverse the stack  */
    //
    void traverseStack();
    
    //*  Remove all elements in the stack  */
    //
    void removeAllObjects();
    
    /*  Print the value from the current node  */
    //
    void print(SingleLinkListNode<Type> *&node);
    
private:
    /*  Private Variables  */
    //
    unsigned int size_;
    unsigned int capacity_;
    SingleLinkListHeadNode<Type> *bottom_;
    
    /*  Private Functions  */
    //
    void push(SingleLinkListHeadNode<Type> *&bottom, const Type& value);
    Type pop(SingleLinkListHeadNode<Type> *&bottom);
    
    void removeAllObjects(SingleLinkListHeadNode<Type> *&bottom);
};

#pragma mark - Construct Function

template<class Type>
Stack<Type>::Stack(){
    bottom_ = new SingleLinkListHeadNode<Type>();
    size_ = 0;
    capacity_ = 100;
}

template<class Type>
Stack<Type>::Stack(const unsigned int& capacity){
    bottom_ = new SingleLinkListHeadNode<Type>();
    size_ = 0;
    capacity_ = capacity;
}

#pragma mark - Basic Functions

template<class Type>
void Stack<Type>::push(const Type &value){
    if (!bottom_) {
        return ;
    }
    push(bottom_, value);
}

template <class Type>
void Stack<Type>::push(SingleLinkListHeadNode<Type> *&bottom, const Type& value){
    if (!bottom) {
        return ;
    }
    SingleLinkListNode<Type> *node = bottom_ -> next;
    while (node) {
        node = node -> next;
    }
    if (size_ == capacity_) {
        cout << "Stack Overflow\n";
        return ;
    }
    SingleLinkList<Type>::insertToHead(bottom_, value);
    size_++;
}

template<class Type>
Type Stack<Type>::pop(){
    if (!bottom_) {
        return 0;
    }
    return pop(bottom_);
}

template <class Type>
Type Stack<Type>::pop(SingleLinkListHeadNode<Type> *&bottom){
    if (!bottom) {
        return ;
    }
    Type value = SingleLinkList<Type>::valueInIndex(bottom, 0);
    SingleLinkList<Type>::deleteIndex(bottom, 0);
    return value;
}

template<class Type>
unsigned int Stack<Type>::size() const{
    if (!bottom_) {
        return 0;
    }
    
    unsigned int size = 0;
    SingleLinkListNode<Type> *node = bottom_ -> next;
    while (node) {
        size++;
        node = node -> next;
    }
    return size;
}

template <class Type>
void Stack<Type>::removeAllObjects(){
    if (!bottom_) {
        return ;
    }
    removeAllObjects(bottom_);
}

template <class Type>
void Stack<Type>::removeAllObjects(SingleLinkListHeadNode<Type> *&bottom){
    if (!bottom) {
        return ;
    }
    
    SingleLinkListNode<Type> *node = bottom -> next;
    while (node) {
        SingleLinkListNode<Type> *temp = node;
        node = node -> next;
        delete temp;
    }
    bottom -> next = NULL;
}

#pragma mark - Traverse Stack

template<class Type>
void Stack<Type>::traverseStack(){
    if (!bottom_) {
        return ;
    }
    
    SingleLinkListNode<Type> *node = bottom_ -> next;
    cout << "Top | ";
    while (node) {
        cout << node -> value << " | ";
        node = node -> next;
    }
    cout << "Bottom\n";
}

template<class Type>
void Stack<Type>::print(SingleLinkListNode<Type> *&node){
    if (node) {
        cout << node -> value;
    }
}

#endif /* defined(__Algorithm_C_____Stack__) */
