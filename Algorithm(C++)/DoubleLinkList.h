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
    
    /*  Construct Function  */
    //
    DoubleLinkList();
    DoubleLinkList(Type value);
    DoubleLinkList(vector<Type> values);
    
    /*  The DLList's length  */
    //
    unsigned int length();
    
    void insertNode(const Type &value);
    
private:
    /*  Private Variable  */
    //
    DoubleLinkListHead<Type> *head_;
    
    /*  Private Function  */
    //
    unsigned int length(DoubleLinkListHead<Type> *&head);
    void insertNode(DoubleLinkListHead<Type> *&head, Type &value);
    void deleteNode(DoubleLinkListHead<Type> *&head, Type &value);
    
};

#pragma mark - Construct Function

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
