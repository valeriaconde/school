//
//  main.cpp
//  Act 5.1
//
//  Created by Valeria Conde on 25/11/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

const char OCUPADO = 'o';
const char LIBRE = 'l';
const char BORRADO = 'b';

bool isPrime(int n) {
    if (n <= 1)  return false;
    if (n <= 3)  return true;
    if (n%2 == 0 || n%3 == 0) return false;
    
    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;
    
    return true;
}
  
int nextPrime(int N) {
    if (N <= 1)
        return 2;
  
    int prime = N;
    bool found = false;
  
    while (!found) {
        prime++;
  
        if (isPrime(prime))
            found = true;
    }
    return prime;
}

// Complejidad: O(n^2)
void open(vector<int> &hasht, vector<char> &flags, vector<int> &ar) {
    for(int i = 0; i < ar.size(); i++) {
        int pos = ar[i] % hasht.size();
        while(flags[pos] == OCUPADO) {
            pos = (pos+1) % hasht.size();
        }
        flags[pos] = OCUPADO;
        hasht[pos] = ar[i];
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> ar;
    
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ar.push_back(x);
    }
    
    int sz = nextPrime(n);
    vector<int> hasht(sz);
    vector<char> flags(sz, LIBRE);
    
    open(hasht, flags, ar);
    
    return 0;
}
