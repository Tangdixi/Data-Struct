//
//  DoubleLinkList.h
//  Algorithm(C++)
//
//  Created by tang dixi on 3/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____DoubleLinkList__
#define __Algorithm_C_____DoubleLinkList__

#include <iostream>
#include <vector>

using namespace std;

template <typename Type>
struct DoubleLinkListNode{
    Type value;
    DoubleLinkListNode<Type> *pre;
    DoubleLinkListNode<Type> *next;
};

template <typename Type>
struct DoubleLinkListHead{
    DoubleLinkListHead()
    :next(NULL){};
    
    DoubleLinkListNode<Type> *next;
};

template <class Type>

class DoubleLinkList {
public:
    
    DoubleLinkList();
    DoubleLinkList(Type value);
    DoubleLinkList(vector<Type> values);
    
    unsigned int length();
    
    void insertNode(const Type &value);
    
private:
    DoubleLinkListHead<Type> *head_;
    unsigned int length(DoubleLinkListHead<Type> *&head);
    
    void insertNode(DoubleLinkListHead<Type> *&head, Type &value);
    void deleteNode(DoubleLinkListHead<Type> *&head, Type &value);
    
};

template <class Type>
DoubleLinkList<Type>::DoubleLinkList(){
    
}

template <class Type>
DoubleLinkList<Type>::DoubleLinkList(Type value){
    if (head_) {
        head_ = new DoubleLinkListHead<Type>();
    }
    insertNode(value);
}

#endif /* defined(__Algorithm_C_____DoubleLinkList__) */
