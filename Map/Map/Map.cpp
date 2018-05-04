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

template <class X, class Y>
list<int>& Map<X,Y>::findBucket(Y key){
    
    int hashCode = f(key);
    int bucketNumber = hashCode % theHashTable.size();
    
    return theHashTable[bucketNumber];
}

template <class X, class Y>
bool Map<X,Y>::containsKey(const X& key){
    
    for(list<int> :: iterator it = theHashTable[findBucket(key)].begin())
    
}
