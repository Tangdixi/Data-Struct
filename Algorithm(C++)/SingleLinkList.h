//
//  SingleLinkList.h
//  Algorithm(C++)
//
//  Created by tang dixi on 28/3/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____SingleLinkList__
#define __Algorithm_C_____SingleLinkList__

#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

#pragma mark - Single Link List Node Struct

template <class Type>
struct SingleLinkListNode{
public:
    SingleLinkListNode()
    :value(0),next(NULL){};
    
    SingleLinkListNode(const Type& value_)
    :value(value_),next(NULL){};
    
    Type value;
    SingleLinkListNode<Type> *next;
};

#pragma mark - Single Link List Head Node Struct

template <class Type>
struct SingleLinkListHeadNode{
public:
    SingleLinkListHeadNode()
    :next(NULL){};
    
    SingleLinkListNode<Type> *next;
};

#pragma Single Link List Class Struct

template <class Type>

class SingleLinkList{
public:
    
    /*  Construct Function 2  */
    explicit SingleLinkList();
    explicit SingleLinkList(const Type& value);
    explicit SingleLinkList(vector<Type>& values);
    
    /*  Destruct Function  */
    //
    ~SingleLinkList();
    
    /*  Access Local Variable  */
    //
    SingleLinkListHeadNode<Type>* head() const;
    
    /*  Print variable in the node  */
    //
    void print(SingleLinkListNode<Type> *&node);
    
    /*  Count Node's number in a list  */
    //
    unsigned int nodeCount() const;
    
    /*  Find a node in a list, return a pointer to the node if the node exist  */
    //
    SingleLinkListNode<Type>* findNode(const Type& value);
    
    /*  Insert a new node to the list behind its head  */
    //
    void insertToHead(const Type& value);
    
    /*  Insert a new node to the list behind its tail  */
    //
    void insertToTail(const Type& value);
    
    /*  Insert a new node to the list in target index  */
    //
    void insertToIndex(const Type& value, unsigned int& index);
    
    /*  Delete a node from a list  */
    //
    void deleteNode(const Type& value);
    
    /*  Delete a node from the list in the target index  */
    //
    void deleteIndex(const unsigned long& index);
    
    /*  Traverse the list   */
    //
    void traverseList();
    
    /*  Traverse a list in a reverse order  */
    //
    void reverseTraverseList();
    
    /*  Judge if a list have a circle  */
    //
    bool hasCircle();
    
    /*  Move the tail pointer to the target node to create a circle in the list  */
    //
    void createCircleToNode(const Type& value);
    
    /*  Find the enterance for the circle in a list  */
    //
    void findCircleEnterance();

    /*  Make Empty  */
    //
    void makeEmpty();
    
    /*  Return the value in target index  */
    //
    Type valueInIndex(const unsigned long& index);
    
private:
    /*  Private variable  */
    //
    SingleLinkListHeadNode<Type> *head_;
protected:
    /*  Protected function  */
    //
    SingleLinkListNode<Type>* findNode(SingleLinkListHeadNode<Type> *&head, const Type& value);
    void insertToHead(SingleLinkListHeadNode<Type> *&head, const Type& value);
    void insertToTail(SingleLinkListHeadNode<Type> *&head, const Type& value);
    void insertToIndex(SingleLinkListHeadNode<Type> *&head, const Type& value, unsigned int& index);
    void deleteNode(SingleLinkListHeadNode<Type> *&head, const Type& value);
    void deleteIndex(SingleLinkListHeadNode<Type> *&head, const unsigned long& index);
    void makeEmpty(SingleLinkListHeadNode<Type> *&head);
    void traverseList(SingleLinkListHeadNode<Type> *&head);
    void reverseTraverseList(SingleLinkListNode<Type> *&node);
    unsigned int nodeCount(SingleLinkListHeadNode<Type> *&head);
    Type valueInIndex(SingleLinkListHeadNode<Type> *&head, const unsigned long& index);
    SingleLinkListNode<Type>* hasCircle(SingleLinkListHeadNode<Type> *&head);
    void createCircleToNode(SingleLinkListHeadNode<Type> *&head, const Type& value);
    SingleLinkListNode<Type>* findCircleEnterance(SingleLinkListHeadNode<Type> *&head);
    SingleLinkListNode<Type>* crossNode(SingleLinkListNode<Type> *&headInFirst, SingleLinkListNode<Type> *&headInSecond, SingleLinkListNode<Type> *&tailNode);
};

#pragma mark - Construct Function

template <class Type>
SingleLinkList<Type>::SingleLinkList(){
    if (!head_) {
        head_ = new SingleLinkListHeadNode<Type>();
    }
}

template <class Type>
SingleLinkList<Type>::SingleLinkList(const Type& value){
    if (!head_) {
        head_ = new SingleLinkListHeadNode<Type>();
    }
    insertToHead(head_, value);
}

template <class Type>
SingleLinkList<Type>::SingleLinkList(vector<Type>& values){
    if (!this -> head_) {
        head_ = new SingleLinkListHeadNode<Type>();
    }
}

#pragma mark - Destruct Function

template <class Type>
SingleLinkList<Type>::~SingleLinkList<Type>(){
    
}

#pragma mark - Destroy the list

template <class Type>
void SingleLinkList<Type>::makeEmpty(){
    if (!head_) {
        return ;
    }
    makeEmpty(head_);
}

template <class Type>
void SingleLinkList<Type>::makeEmpty(SingleLinkListHeadNode<Type> *&head){
    if (!head) {
        return ;
    }
    SingleLinkListNode<Type> *node = head -> next;
    while (node) {
        SingleLinkListNode<Type> *temp = node;
        node = node -> next;
        delete temp;
    }
    delete head;
}

#pragma mark - Access  Private Variable

template <class Type>
SingleLinkListHeadNode<Type>* SingleLinkList<Type>::head() const{
    return this -> head_;
}

#pragma mark - Basic Function

template <class Type>
unsigned int SingleLinkList<Type>::nodeCount() const{
    if (!head_) {
        return 0;
    }
    return nodeCount(head_);
}

template <class Type>
unsigned int SingleLinkList<Type>::nodeCount(SingleLinkListHeadNode<Type> *&head){
    SingleLinkListNode<Type> *node = head -> next;
    
    unsigned int length = 0;
    while (node) {
        length++;
        node = node -> next;
    }
    return length;
}

template <class Type>
void SingleLinkList<Type>::print(SingleLinkListNode<Type> *&node){
    if (node) {
        cout  << node -> value << " -> ";
    }
}

template <class Type>
Type SingleLinkList<Type>::valueInIndex(const unsigned long &index){
    if (!head_) {
        return 0;
    }
    valueInIndex(head_, index);
}

template <class Type>
Type SingleLinkList<Type>::valueInIndex(SingleLinkListHeadNode<Type> *&head, const unsigned long& index){
    if (!head) {
        return 0;
    }
    SingleLinkListNode<Type> *node = head -> next;
    for (int i = 0; i < index ; i++) {
        node = node -> next;
    }
    if (node) {
        return node -> value;
    }
    return 0;
}

#pragma mark - Delete Node

template <class Type>
void SingleLinkList<Type>::deleteNode(const Type &value){
    if (!head_) {
        return ;
    }
    deleteNode(head_, value);
}

template <class Type>
void SingleLinkList<Type>::deleteNode(SingleLinkListHeadNode<Type> *&head, const Type &value){
    if (!head) {
        return ;
    }
    SingleLinkListNode<Type> *node = head -> next;
    
    if (!node) {
        return ;
    }
    
    while (node -> next != NULL) {
        if (node -> next -> value == value) {
            break;
        }
        node = node -> next;
    }
    
    SingleLinkListNode<Type> *temp = node -> next;
    node -> next = temp -> next;
    delete temp;
    
}

template<class Type>
void SingleLinkList<Type>::deleteIndex(const unsigned long &index){
    if (!head_) {
        return ;
    }
    deleteIndex(head_, index);
}

template<class Type>
void SingleLinkList<Type>::deleteIndex(SingleLinkListHeadNode<Type> *&head, const unsigned long& index){
    if (!head) {
        return ;
    }
    SingleLinkListNode<Type> *node = head -> next;
    
    if (node) {
        if (index == 0) {
            head -> next = node -> next;
            delete node;
            return ;
        }
        
        for (int i = 0; i < index - 1; i++) {
            node = node -> next;
        }
        SingleLinkListNode<Type> *currentNode = node -> next;
        node -> next = currentNode -> next;
        delete currentNode;
    }
}

#pragma mark - Insert to List

template <class Type>
void SingleLinkList<Type>::insertToHead(const Type &value){
    if (!head_) {
        return ;
    }
    insertToHead(head_, value);
}

template <class Type>
void SingleLinkList<Type>::insertToHead(SingleLinkListHeadNode<Type> *&head, const Type &value){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode<Type> *node = new SingleLinkListNode<Type>(value);
    
    if (!node) {
        cout << "Node init failure\n";
        return ;
    }
    
    node -> next = head -> next;
    head -> next = node;
    
}

template <class Type>
void SingleLinkList<Type>::insertToTail(const Type &value){
    if (!head_) {
        return ;
    }
    insertToTail(head_, value);
}

template <class Type>
void SingleLinkList<Type>::insertToTail(SingleLinkListHeadNode<Type> *&head, const Type &value){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode<Type> *currentNode = head -> next;
    
    if (!currentNode) {
        currentNode = new SingleLinkListNode<Type>(value);
        currentNode -> next = head -> next;
        head -> next = currentNode;
        return ;
    }
    
    while (currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    
    SingleLinkListNode<Type> *node = new SingleLinkListNode<Type>(value);
    node -> next = currentNode -> next;
    currentNode -> next = node;
    
}

template <class Type>
void SingleLinkList<Type>::insertToIndex(const Type &value, unsigned int &index){
    if (!head_) {
        return ;
    }
    insertToIndex(head_, value, index);
}

template <class Type>
void SingleLinkList<Type>::insertToIndex(SingleLinkListHeadNode<Type> *&head, const Type &value, unsigned int& index){
    if (!head) {
        cout << "Head node no found\n";
        return ;
    }
    
    SingleLinkListNode<Type> *current = head -> next;
    
    for (int i = 0; i < index - 1; i++) {
        if (!current) {
            cout << "Out of limit\n";
            return ;
        }
        current = current -> next;
    }
    
    SingleLinkListNode<Type> *node = new SingleLinkListNode<Type>(value);
    
    node -> next = current -> next;
    current -> next = node;
    
}

#pragma mark - Traverse List

template <class Type>
void SingleLinkList<Type>::traverseList(){
    if (!head_) {
        return ;
    }
    traverseList(head_);
}

template <class Type>
void SingleLinkList<Type>::traverseList(SingleLinkListHeadNode<Type> *&head){
    if (!head) {
        return ;
    }
    
    SingleLinkListNode<Type> *circleEnterance = NULL;
    bool enterCircle = false;
    
    if (hasCircle(head)) {
        circleEnterance = findCircleEnterance(head);
    }
    
    cout << "Head -> ";
    
    SingleLinkListNode<Type> *node = head -> next;
    
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

template <class Type>
void SingleLinkList<Type>::reverseTraverseList(){
    if (!head_) {
        return ;
    }
    cout << "Tail -> ";
    reverseTraverseList(head_ -> next);
    cout << " Head";
}

template <class Type>
void SingleLinkList<Type>::reverseTraverseList(SingleLinkListNode<Type> *&node){
    if (!node) {
        return ;
    }
    else {
        reverseTraverseList(node -> next);
        print(node);
    }
}

#pragma mark - Has Circle

template <class Type>
bool SingleLinkList<Type>::hasCircle(){
    if (!head_) {
        return false;
    }
    if (!hasCircle(head_)) {
        return false;
    }
    return true;
}

template <class Type>
SingleLinkListNode<Type>* SingleLinkList<Type>::hasCircle(SingleLinkListHeadNode<Type> *&head){
    if (!head) {
        return NULL;
    }
    
    SingleLinkListNode<Type> *fastPointer = head -> next;
    SingleLinkListNode<Type> *slowPointer = head -> next;
    
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

template <class Type>
SingleLinkListNode<Type>* SingleLinkList<Type>::findNode(const Type &value){
    if (!head_) {
        return NULL;
    }
    return findNode(head_, value);
}

template <class Type>
SingleLinkListNode<Type>* SingleLinkList<Type>::findNode(SingleLinkListHeadNode<Type> *&head, const Type& value){
    if (!head) {
        return NULL;
    }
    
    SingleLinkListNode<Type> *currentNode = head -> next;
    
    while (currentNode -> value != value && currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    return currentNode;
}

#pragma mark - Create Circle

template <class Type>
void SingleLinkList<Type>::createCircleToNode(const Type &value){
    if (!head_) {
        return ;
    }
    createCircleToNode(head_, value);
}

template <class Type>
void SingleLinkList<Type>::createCircleToNode(SingleLinkListHeadNode<Type> *&head, const Type &value){
    if (!head) {
        return ;
    }
    SingleLinkListNode<Type> *currentNode = head -> next;
    
    if (!currentNode) {
        return ;
    }
    
    while (currentNode -> next != NULL) {
        currentNode = currentNode -> next;
    }
    
    SingleLinkListNode<Type> *targetNode = findNode(value);
    currentNode -> next = targetNode;
}

#pragma mark - Find the Enterance of Circle

template <class Type>
void SingleLinkList<Type>::findCircleEnterance(){
    if (!head_) {
        return ;
    }
    cout << "The circle enterance is " << findCircleEnterance(head_) -> value << '\n';
}

template <class Type>
SingleLinkListNode<Type>* SingleLinkList<Type>::findCircleEnterance(SingleLinkListHeadNode<Type> *&head){
    SingleLinkListNode<Type> *slowPointer = hasCircle(head);
    if (!slowPointer) {
        cout << "Has no Circle!\n";
        return NULL;
    }
    
    SingleLinkListNode<Type> *fakeTail = slowPointer;
    
    SingleLinkListNode<Type> *firstTempListHead = head -> next;
    SingleLinkListNode<Type> *secondTempListHead = slowPointer -> next;
    
    return crossNode(firstTempListHead, secondTempListHead, fakeTail);
}

#pragma mark - Cross to List

template <class Type>
SingleLinkListNode<Type>* SingleLinkList<Type>::crossNode(SingleLinkListNode<Type> *&headInFirst, SingleLinkListNode<Type> *&headInSecond, SingleLinkListNode<Type> *&tailNode){
    if (!headInFirst || !headInSecond) {
        return NULL;
    }
    
    int firstListLength = 0;
    int secondListLength = 0;
    
    SingleLinkListNode<Type> *firstHead = headInFirst;
    SingleLinkListNode<Type> *secondHead = headInSecond;
    SingleLinkListNode<Type> *tempFirstHead = firstHead;
    SingleLinkListNode<Type> *tempSecondHead = secondHead;
    
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

#endif /* defined(__Algorithm_C_____SingleLinkList__) */
