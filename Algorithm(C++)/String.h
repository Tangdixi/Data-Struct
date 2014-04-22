//
//  String.h
//  Algorithm(C++)
//
//  Created by tang dixi on 22/4/14.
//  Copyright (c) 2014 Tangdxi. All rights reserved.
//

#ifndef __Algorithm_C_____String__
#define __Algorithm_C_____String__

#include <iostream>

using namespace std;

class String {
public:
    
    /*  Construct Function  */
    //
    String();
    String(const char *string);
    
    /*  Destruct Functions  */
    //
    ~String();
    
    /*  Overload Operator  */
    //
    String& operator = (const String& string);
    char& operator [ ] (const unsigned int& offset);
    String& operator + (const String& string);
    
    /*  Overload Output Stream  */
    //
    friend ostream& operator << (ostream& outputStream, const String& string);
    
    /*  Access Private Variable  */
    //
    unsigned long stringLength() const;
    
private:
    char *string_;
    unsigned long stringLength_;
    
};


#endif /* defined(__Algorithm_C_____String__) */
