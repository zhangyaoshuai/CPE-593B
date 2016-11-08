//
//  truncPrimes.cpp
//  truncPrimes
//
//  Created by EricZhang on 9/30/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(long n) {
    if (n == 1) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0 ) {
            return false;
        }
    }
    return true;
}

int numOfDigits(long n) {
    int d = 0;
    while (n/10 > 0) {
        n = n/10;
        d++;
    }
    return d;
}

bool leftTrunc(long n) {
    if (n < 10) {
        return isPrime(n);
    }
    return isPrime(n) && leftTrunc(n % long(pow(10.0,double(numOfDigits(n)))));
}

bool rightTrunc(long n) {
    if (n < 10) {
        return isPrime(n);
    }
    return isPrime(n) && rightTrunc(n/10);
}

bool isTruncPrime(long n) {
    
    return leftTrunc(n) && rightTrunc(n);
    
}


int main() {
    
    long sum = 0;
    int n =0;
    long i = 11;
    while (n < 11) {
        if (isTruncPrime(i)) {
            cout << i << endl;
            sum += i;
            n++;
        }
        i += 2;
    }
    cout << sum << endl;
    
}




