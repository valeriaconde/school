//
//  main.cpp
//  act 3.2
//
//  Created by Valeria Conde on 17/10/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include "priority_queue.h"
int main() {
    priority_queue heap;
    
    // PUSH
    heap.push(6);
    heap.push(23);
    heap.push(9);
    heap.push(16);
    heap.push(61);
    heap.push(4);
    
    // SIZE
    cout << "Size of heap: " << heap.size() << endl; // 6
    
    // TOP & POP
    cout << "Printing heap" << endl;
    while(!heap.empty()) {
        int tmp = heap.top();
        heap.pop();
        
        cout << tmp << endl;
    }
    
    // SIZE
    cout << "New size of heap: " << heap.size() << endl; // 0
    
    // EMPTY
    cout << "Is heap empty? -> " << heap.empty() << endl; // 1
    
    return 0;
}
