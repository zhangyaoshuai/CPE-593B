//
//  main.cpp
//  MillerRabin
//
//  Created by EricZhang on 9/10/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

int powerMod(int a,int n,int m) {
    int prod = 1;
    while(n >0 ) {
        if(n % 2 != 0) {
            prod = prod * a % m;
            n = n-1;
        }
        n = n/2;
        a = a * a % m;
    }
    return prod;
}
bool MillerRabin(int sample) {
    int orig = sample;
    sample -= 1;
    int r = 0;
    bool flag = false;
    while (sample % 2 == 0) {
        sample = sample/2;
        r++;
    }
    if(orig == 2)
        return true;
    for (int k = 0; k < log(orig); k ++) {
        
        int a = rand() % (orig-2) + 2;
        int x = powerMod(a,sample,orig);
        if (x == 1 || x == orig - 1) continue;
        for (int i = 0; i < r; i ++) {
            x = (x * x) % orig;
            if(x == 1) return false;
            if(x == orig -1 ) {
                flag = true;
                break;
            }
        }
        if(flag) continue;
        else return false;
        
    }
    return true;
}
int main() {
    
    ifstream myfile("hw2.dat");
    
    if(myfile.fail()) {
        cout << "Failed to open file 'hw2.dat'" << endl;
    }
    
    while(myfile.good()) {
        int num;
        myfile >> num;
        if(MillerRabin(num)) {
            cout << num << ": " << "True" << '\n';
        }
        else {
            cout << num << ": " << "False" << '\n';
        }
        
    }
    
    myfile.close();

    return 0;
    
}






