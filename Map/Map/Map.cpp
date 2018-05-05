//
//  Map.cpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <stdio.h>
#include "Map.hpp"

using namespace std;

bool Map::containsKey(const string& key){
    
    int bucket = findBucket(key);
    
    list<ENTRY>& bucketToSearch = theHashTable[bucket];
    
    for(list<ENTRY>::iterator it = bucketToSearch.begin(); it != bucketToSearch.end(); it++)
        if(it -> getKey() == key)
            return true;
    
    return false;
}

bool Map::containsValue(int value){
    
    for(int i = 0; i < theHashTable.size(); i++)
        for(list<ENTRY> :: iterator it = theHashTable[i].begin(); it != theHashTable[i].end(); it++)
            if(it -> getValue() == value)
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
        if(it -> getKey() == key)
            theHashTable[bucket].erase(it);
}

int Map::getValueOf(const string& key){
    
    if (containsKey(key) == false)
        return -1;
    
    int bucket = findBucket(key);
    
    list<ENTRY>& bucketWithKey = theHashTable[bucket];
    
    for(list<ENTRY> :: iterator it = bucketWithKey.begin(); it != bucketWithKey.end(); it++)
        if(it -> getKey() == key)
            return it -> getValue();
    
    return -1;
}


