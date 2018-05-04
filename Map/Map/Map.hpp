//
//  Map.hpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#ifndef Map_hpp
#define Map_hpp

#include <iostream>
#include <list>

using namespace std;

template <class X, class Y>
class Map {
   
    private:
        vector<list<pair<X,Y>>> theHashTable;
        list<int>& findBucket(Y);
    
        template<class HASHFN>
        HASHFN f;
    
   
    public:
        void insert(const X&, Y);
        bool containsKey(const X&);
        bool containsValue(Y);
        void erase(const X&);
        Y getValueOf(const X&);
        Y& operator[](const X&);
        int size();
        bool empty();
    
};


#endif /* Map_hpp */
