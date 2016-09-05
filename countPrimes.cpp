//
//  main.cpp
//  HW1(countPrime)
//
//  Created by EricZhang on 9/1/16.
//  Copyright (c) 2016 EricZhang. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int countPrime(int n) {
    bool* isPrime = new bool[n];
    for(int i = 2; i < n; i ++) {
        isPrime[i] = true;
    }
    for(int i = 2; i < sqrt(n); i ++) {
        if(isPrime[i] == true) {
            for(int j = i*i; j < n; j += i) {
                isPrime[j] = false;
            }
        }
    }
    int num = 0;
    for(int i = 2; i <= n; i ++) {
        if(isPrime[i] == true)
            num += 1;
        
        
    }
    delete[] isPrime;
    return num;
}

int main() {
    int m, n;
    cout << "please input a number:";
    cin >> m;
    cout << '\n';
    cout << "Input another number:";
    cin >> n;
    cout << '\n';
    if (n > m){
        cout << countPrime(n) - countPrime(m);
    }
    else {
        cout << countPrime(m) - countPrime(n);
    }
    cout<<endl;
    
}