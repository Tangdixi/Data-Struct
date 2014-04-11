//
//  BinaryHeap.h
//  Algorithm(C++)
//
//  Created by tang dixi on 9/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____BinaryHeap__
#define __Algorithm_C_____BinaryHeap__

#include <iostream>
#include "BinarySearchTree.h"

#define MAX_HEAP false
#define MIN_HEAP true

using namespace std;

template <class Type>

class BinaryHeap {
public:
    /*  Construct Function  */
    //
    explicit BinaryHeap();
    explicit BinaryHeap(const unsigned int &capacity, bool heapType);
    explicit BinaryHeap(vector<Type>& values, bool heapType);
    
    /*  Insert a new node into BinaryHeap  */
    //
    void insertNode(const Type& value);
    
    /*  Insert new nodes into BinaryHeap  */
    //
    void insertNode(vector<Type>& values);
    
    /*  Traverse the BinaryHeap   */
    //
    void traverseHeap();
    
    /*  Percolate Down the hole in the BinaryHeap */
    //
    void percolateDown(unsigned long index);
    
    /*  Percolate Up  in the BinaryHeap */
    //
    void percolateUp(unsigned long index, const Type& value);
    
    /*  Delete Min  */
    //
    void deleteMin();
    
    /*  Judge the current node in the BinaryHeap is a leaf  */
    //
    bool isLeaf(const unsigned long& index);
    
private:
    /*  Private Variable  */
    //
    unsigned int heapCapacity_;
    unsigned long heapSize_;
    vector<Type> heapArray_;
    bool heapType_;
    
    /*  Private Functions  */
    //
    void constructHeap(vector<Type>& values);
    void print(vector<Type>& values);
};

#pragma mark - Construct Function

template <class Type>
BinaryHeap<Type>::BinaryHeap(){
    heapType_ = MIN_HEAP;
}

template <class Type>
BinaryHeap<Type>::BinaryHeap(const unsigned int& capacity, bool heapType){
    heapCapacity_ = capacity;
    vector<Type> heapArray(heapCapacity_);
    heapArray_ = heapArray;
    heapType_ = heapType;
}

template <class Type>
BinaryHeap<Type>::BinaryHeap(vector<Type>& values, bool heapType){
    heapCapacity_ = 100;
    vector<Type> heapArray(heapCapacity_);
    heapArray_ = heapArray;
    
    for (int i = 0; i < values.size(); i++) {
        heapArray_[i + 1] = values[i];
        heapSize_++;
    }
    heapType_ = heapType;
    constructHeap(heapArray_);
}

template <class Type>
void BinaryHeap<Type>::constructHeap(vector<Type>& values){
//    for (unsigned long i = heapSize_ / 2; i > 0; i--) {
//        percolateDown(i);
//    }
    percolateDown(4UL);
    percolateDown(3UL);
    percolateDown(2UL);
    percolateDown(1UL);
    
}

#pragma mark - Insert Function

template <class Type>
void BinaryHeap<Type>::insertNode(const Type& value){
    if (heapSize_ - 1 == heapCapacity_) {
        heapArray_.resize(heapCapacity_ * 2);
        heapCapacity_ = heapCapacity_ * 2;
    }
    
    unsigned long targetIndex = ++heapSize_ ;
    
    percolateUp(targetIndex, value);
}

template <class Type>
void BinaryHeap<Type>::insertNode(vector<Type>& values){
    
}

#pragma mark - Delete Min 

template <class Type>
void BinaryHeap<Type>::deleteMin(){
    if (heapArray_.empty()) {
        return ;
    }
    percolateDown(1);
}

#pragma mark - Percolate Functions

template <class Type>
void BinaryHeap<Type>::percolateUp(unsigned long index, const Type& value){
    unsigned long parentIndex = index / 2;
    
    while (index > 1 && (heapType_ == MIN_HEAP ? (heapArray_[parentIndex] > value) : (heapArray_[parentIndex] < value))) {
        heapArray_[index] = heapArray_[parentIndex];
        index = parentIndex;
        parentIndex = parentIndex / 2;
    }
    
    heapArray_[index] = value;
}

template <class Type>
void BinaryHeap<Type>::percolateDown(unsigned long index){
    Type temp = heapArray_[index];
    unsigned long childIndex = index * 2;
    
    while (childIndex <= heapSize_ ) {
        if (childIndex != heapSize_  && (heapType_ == MIN_HEAP ? (heapArray_[childIndex] > heapArray_[childIndex + 1]) : (heapArray_[childIndex] < heapArray_[childIndex + 1]))) {
            childIndex++;
        }
        
        if ((heapType_ == MIN_HEAP ? (heapArray_[childIndex] <= temp) : (heapArray_[childIndex] >= temp))) {
            heapArray_[index] = heapArray_[childIndex];
        }
        else {
            break ;
        }
        index = childIndex;
        childIndex = childIndex * 2;
    }
    
    heapArray_[index] = temp;
}

#pragma mark - Print the BinaryHeap

template <class Type>
void BinaryHeap<Type>::traverseHeap(){
    if (heapArray_.empty()) {
        return ;
    }
    print(heapArray_);
}

template <class Type>
void BinaryHeap<Type>::print(vector<Type> &values){
    if (values.empty()) {
        return ;
    }
    
    cout << " Heap -> ";
    
    typename vector<Type>::iterator iter(values.begin() + 1);
    
    for (int i = 1; i <= heapSize_; i++) {
        cout << *iter << " -> ";
        iter++;
    }
    
    cout << " NULL ";
}

#pragma mark - Judge the leaf node

template <class Type>
bool BinaryHeap<Type>::isLeaf(const unsigned long &index){
    if (index * 2 > heapSize_ && index <= heapSize_) {
        return true;
    }
    return false;
}

#endif /* defined(__Algorithm_C_____BinaryHeap__) */
