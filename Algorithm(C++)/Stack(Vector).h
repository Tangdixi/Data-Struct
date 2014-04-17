//
//  Stack(Vector).h
//  Algorithm(C++)
//
//  Created by tang dixi on 17/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____Stack_Vector___
#define __Algorithm_C_____Stack_Vector___

#include <iostream>
#include <vector>
#include "SingleLinkList.h"

template <class Type>
class Stack : public SingleLinkList<Type> {
public:
    /*  Construct Function  */
    //
    explicit Stack<Type>();
    explicit Stack<Type>(const unsigned int& capacity);
    
    /*  Push the element into the Stack  */
    //
    void push(const Type& value);
    
    /*  Pop the element from the Stack  */
    //
    Type pop();
    
    /*  Traverse the Stack  */
    //
    void traverseStack();
    
    /*  Print the object from the current node  */
    //
    void print(const unsigned long& index);
    
    /*  Remove all objects in the Stack  */
    //
    void removeAllObjects();
    
private:
    /*  Private Variables  */
    //
    vector<Type> stackArray_;
    unsigned int capacity_;
    unsigned int size_;
};

#pragma mark - Construct Functions

template <class Type>
Stack<Type>::Stack() {
    vector<Type> stackArray(100);
    stackArray_ = stackArray;
    capacity_ = 100;
    size_ = 0;
}

template <class Type>
Stack<Type>::Stack(const unsigned int& capacity) {
    vector<Type> stackArray(capacity);
    stackArray_ = stackArray;
    capacity_ = capacity;
    size_ = 0;
}

#pragma mark - Basic Functions

template <class Type>
void Stack<Type>::push(const Type &value) {
    if (size_ == capacity_) {
        cout << "Stack Overflow\n";
        return ;
    }
    size_++;
    stackArray_.push_back(value);
}

template <class Type>
Type Stack<Type>::pop(){
    if (stackArray_.empty()) {
        return 0;
    }
    Type object = stackArray_[size_];
    size_--;
    return object;
}

template <class Type>
void Stack<Type>::removeAllObjects(){
    size_ = 0;
}

#pragma mark - Traverse the Stack

template <class Type>
void Stack<Type>::traverseStack(){
    if (stackArray_.empty()) {
        cout << "Bottom | Top\n";
        return ;
    }
    
    cout << "Bottom ";
    for (typename vector<Type>::iterator iter(stackArray_.end() - size_); iter != stackArray_.end(); iter++) {
        cout << " | " << *iter;
    }
    cout << " | Top \n";
}

#pragma mark - Print

template <class Type>
void Stack<Type>::print(const unsigned long &index){
    if (index > size_) {
        return ;
    }
    cout << stackArray_[index];
}

#endif /* defined(__Algorithm_C_____Stack_Vector___) */
