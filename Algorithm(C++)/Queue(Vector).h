//
//  Queue(Vector).h
//  Algorithm(C++)
//
//  Created by tang dixi on 18/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____Queue_Vector___
#define __Algorithm_C_____Queue_Vector___

#include <iostream>
#include <vector>

using namespace std;

template <class Type>
class Queue {
public:
    
private:
    unsigned int capacity_;
    unsigned int size_;
    typename vector<Type>::iterator front;
    typename vector<Type>::iterator rear;
    
};
#endif /* defined(__Algorithm_C_____Queue_Vector___) */
