//
//  String.cpp
//  Algorithm(C++)
//
//  Created by tang dixi on 22/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#include "String.h"

#pragma mark - Construct Function

String::String(){
    if (!string_) {
        stringLength_ = 1;
        string_ = new char[stringLength_];
        *string_ = '\0';
    }
}

String::String(const char *string){
    if (!string_) {
        stringLength_ = strlen(string);
        string_ = new char[stringLength_];
        strcpy(string_, string);
    }
}

#pragma mark - Destruct Functions

String::~String(){
    delete [] string_;
    stringLength_ = 0;
}

#pragma mark - Overload Operator

String& String::operator = (const String &string){
    if (this == &string) {
        return *this;
    }
    delete [] string_;
    string_ = new char[string.stringLength()];
    strcpy(string_, string.string_);
    return *this;
}

char& String::operator[](const unsigned int &offset){
    if (offset >= stringLength_) {
        return string_[stringLength_ - 1];
    }
    return string_[offset];
}

String& String::operator+(const String &string){
    if (this == &string) {
        return *this;
    }
    char *temp = new char[stringLength_ + string.stringLength()];
    strcpy(temp, string_);
    strcat(temp, string.string_);
    
    delete [] string_;
    string_ = temp;
    stringLength_ = strlen(temp);
    return *this;
}

#pragma mark - Overload Output Stream

ostream& operator << (ostream& outputStream, const String& string){
    outputStream << string.string_;
    return outputStream;
}

#pragma mark - Access Private Variables

unsigned long String::stringLength() const {
    return stringLength_;
}




