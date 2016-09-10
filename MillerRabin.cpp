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
#include <time.h>
#include <vector>
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
    for (int k = 0; k < log(orig); k ++) {
        srand(time(NULL));
        int a = rand() % (orig - 2) + 2;
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
    vector<int> mynumbers;
    ifstream numberfile;
    int i;
    try {
        numberfile.open("hw2.dat");
    }
    catch (string e) {
        cout << "Unable to open file: " << "hw2.dat";
    }
    while(numberfile.good()) {
        numberfile >> i;
        mynumbers.push_back(i);
    }
    numberfile.close();
    for(int i = 0; i < sizeof(mynumbers); i ++) {
        if(MillerRabin(mynumbers[i])) {
            cout << mynumbers[i] << ": " << "True";
        }
        else {
            cout << mynumbers[i] << ": " << "False";
        }
    }
    return 0;
}






