//
//  ENTRY.h
//  Map
//
//  Created by Jonathan Raysor on 5/4/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef ENTRY_h
#define ENTRY_h

using namespace std;

class ENTRY{

private:
    string key;
    int value;
    
public:
    
    ENTRY(const string& key, const int value=0):key(key), value(value){}
    
    string getKey(){
        return key;
    }
    
    int getValue(){
        return value;
    }
    
    void setValue(int value){
        value = value;
    }
};

#endif /* ENTRY_h */
