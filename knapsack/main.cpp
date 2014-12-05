//
//  main.cpp
//  knapsack
//
//  Created by Dan Shevlyuk on 12/4/14.
//  Copyright (c) 2014 Dan Shevlyuk. All rights reserved.
//

#include <iostream>
#include "knapsack.h"


int main(int argc, const char * argv[]) {
    
    item* items = new item[6];
    items[0] = item(55, 3);
    items[1] = item(80, 2);
    items[2] = item(60, 4);
    items[3] = item(45, 1);
    items[4] = item(105, 3);
    items[5] = item(50, 1);
    
    knapsack ks;
    
    
    cout << ks.dynamic_knapsack(items, 6, 10);
    
    
    
    return 0;
}
