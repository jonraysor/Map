//
//  Map.cpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <stdio.h>
#include "Map.hpp"
#include "ValueNotFoundException.h"

using namespace std;

bool Map::containsKey(const string& key){
    
    int bucket = findBucket(key);
    
    list<ENTRY>& bucketToSearch = theHashTable[bucket];
    
    for(list<ENTRY>::iterator it = bucketToSearch.begin(); it != bucketToSearch.end(); it++)
        if(it -> first == key)
            return true;
    
    return false;
}

bool Map::containsValue(int value){
    
    for(int i = 0; i < theHashTable.size(); i++)
        for(list<ENTRY> :: iterator it = theHashTable[i].begin(); it != theHashTable[i].end(); it++)
            if(it -> second == value)
                return true;
    
    return false;
}

void Map::insert(const string& key, const int value=0){
    
    if(containsKey(key) == true)
        return;
    
    ENTRY toBeEntered(key,value);
    
    int bucket = findBucket(key);
    
    theHashTable[bucket].push_back(toBeEntered);
}

void Map::erase(const string& key){
    
    if(containsKey(key) == false)
        return;
    
    int bucket = findBucket(key);
    
    for(list<ENTRY> :: iterator it = theHashTable[bucket].begin(); it != theHashTable[bucket].end(); it++)
        if(it -> first == key)
            theHashTable[bucket].erase(it);
}

int Map::getValueOf(const string& key){
    
    if (containsKey(key) == false){
        string errorMessage = "In Map::getValueof() an exception was thrown: Key not found.";
        ValueNotFoundException error(errorMessage);
        throw error;
    }
    int bucket = findBucket(key);
    
    list<ENTRY>& bucketWithKey = theHashTable[bucket];
    int valueToReturn = -1;
    
    for(list<ENTRY> :: iterator it = bucketWithKey.begin(); it != bucketWithKey.end(); it++)
        if(it -> first == key)
            valueToReturn = it -> second;
    
    if(valueToReturn == -1){
        string errorMessage = "In Map::getValueof() an exception was thrown: Key not found.";
        ValueNotFoundException error(errorMessage);
        throw error;
    }
    
    return valueToReturn;
}

int& Map::operator[](const string& key){

    if (containsKey(key)){
        
        int bucket = findBucket(key);
        
        list<ENTRY>& bucketWithKey = theHashTable[bucket];
            for(list<ENTRY> :: iterator it = bucketWithKey.begin(); it != bucketWithKey.end(); it++)
                if(it -> first == key)
                    return it -> second;
    }
    
        insert(key);
        int bucket = findBucket(key);
        
        list<ENTRY>& bucketWithKey = theHashTable[bucket];
        for(list<ENTRY> :: iterator it = bucketWithKey.begin(); it != bucketWithKey.end(); it++)
            if(it -> first == key)
                return it -> second;
    return;
}


