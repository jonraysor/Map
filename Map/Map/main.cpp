//
//  main.cpp
//  Map
//
//  Created by Jonathan Raysor on 5/3/18.
//  Copyright © 2018 Jonathan Raysor. All rights reserved.
//

#include <iostream>
#include "Map.hpp"


int main(int argc, const char * argv[]) {

    Map people;
    
    people.insert("jonathan", 20);
    
    cout << people.size();
    return 0;
}
