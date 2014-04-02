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

struct SingleLinkListNode{
    SingleLinkListNode()
    :value(0),next(NULL){};
    
    SingleLinkListNode(const int& value_)
    :value(value_),next(NULL){};
    
    int value;
    SingleLinkListNode *next;
};

struct SingleLinkListHeadNode{
    SingleLinkListHeadNode()
    :next(NULL){};
    
    SingleLinkListNode *next;
};

using namespace std;

class SingleLinkList{
public:
    SingleLinkList();
    SingleLinkList(const int& value);
    SingleLinkList(vector<int> values);
    
    SingleLinkListHeadNode* head() const;
    void print(SingleLinkListNode *&node);
    
    void insertToHead(const int& value);
    void insertToHead(SingleLinkListHeadNode *&head, const int& value);
    void insertToTail(const int& value);
    void insertToTail(SingleLinkListHeadNode *&head, const int& value);
    void insertToIndex(const int& value, const int& index);
    void insertToIndex(SingleLinkListHeadNode *&head, const int& value, const int& index);
    
    void deleteNode(const int& value);
    void deleteNode(SingleLinkListHeadNode *&head, const int& value);
    void deleteIndex(const int& value, const int& index);
    void deleteIndex(SingleLinkListHeadNode *&head, const int& value, const int& index);
    
    void traverseList();
    void traverseList(SingleLinkListHeadNode *&head);
    
    bool hasCircle();
    SingleLinkListNode* hasCircle(SingleLinkListHeadNode *&head);
    
    SingleLinkListNode* findNode(const int& value);
    SingleLinkListNode* findNode(SingleLinkListHeadNode *&head, const int& value);
    
    void createCircleToNode(const int& value);
    void createCircleToNode(SingleLinkListHeadNode *&head, const int& value);
    
    void findCircleEnterance();
    SingleLinkListNode* findCircleEnterance(SingleLinkListHeadNode *&head);
    
    SingleLinkListNode* crossNode(SingleLinkListNode *&headInFirst, SingleLinkListNode *&headInSecond, SingleLinkListNode *&tailNode);
    
private:
    SingleLinkListHeadNode *head_;
};

#endif /* defined(__Algorithm_C_____SingleLinkList__) */
