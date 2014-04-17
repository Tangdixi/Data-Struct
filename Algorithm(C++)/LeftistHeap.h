//
//  LeftistHeap.h
//  Algorithm(C++)
//
//  Created by tang dixi on 11/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____LeftistHeap__
#define __Algorithm_C_____LeftistHeap__

#include <iostream>

template <typename Type>
struct LeftistHeapNode {
    
    LeftistHeapNode<Type>()
    :value(0), npl(0), left(NULL), right(NULL){};
    
    LeftistHeapNode<Type>(const Type& value_)
    :value(value_), npl(0), left(NULL), right(NULL){};
    
    Type value;
    unsigned int npl;
    LeftistHeapNode *left;
    LeftistHeapNode *right;
    
};

template <class Type>
class LeftistHeap {
public:
    
private:
    LeftistHeapNode<Type> *root_;
    
};


#endif /* defined(__Algorithm_C_____LeftistHeap__) */
