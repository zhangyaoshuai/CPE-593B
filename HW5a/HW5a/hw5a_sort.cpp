//
//  main.cpp
//  HW5a
//
//  Created by EricZhang on 10/24/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;

//insertion sort
vector<int> insertionSort(vector<int> num) {
    for (int i = 1; i < num.size(); i++) {
        for (int j = i; j > 0 && num[j - 1] > num[j]; j--) {
            int tmp = num[j];
            num[j] = num[j - 1];
            num[j - 1] = tmp;
        }
    }
    return num;
}

//quick sort
int partition(vector<int> A, int left, int right, int who) {
    for (int i=left; i<right; ++i) {
        if (A[i] <= who) {
            swap(A[i], A[left]);
            left ++;
        }
    }
    return left - 1;
}
void quickSort(vector<int> num, int left, int right) {
    if(left >= right) return;
    int middle = left + (right - left) / 2;
    swap(num[middle], num[left]);
    int midpoint = partition(num, left + 1, right, num[left]);
    swap(num[left], num[midpoint]);
    quickSort(num, left, midpoint);
    quickSort(num, midpoint + 1, right);
}

vector<int> generateRandom(int size, int max) {
    vector<int> array;
    while(size > 0) {
        array.push_back(rand() % max);
        size--;
    }
    return array;
}
void PRINT(vector<int> array) {
    for(int i = 0; i < array.size(); i ++) {
        cout << array[i] << " ";
    }
    cout << endl;
}


void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) elems.push_back(item);
    }
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


int main() {
    string line;
    int num = 0;
    vector<string> str;
    vector<int> array;
    vector<int> arr;
    string filename = "HW5a.txt";
    ifstream myfile(filename);
    if(myfile.fail()) {
        cout << "Failed to open file!" << endl;
    }
    while(getline(myfile, line)) {
        str = split(line, ' ');
        if(str[0] == "PRINT" && str[1] == "RANDOM") {
            int size = stoi(str[2]);
            int max = stoi(str[3]);
            array = generateRandom(size, max);
            PRINT(array);
            array = insertionSort(array);
            //quickSort(array, 0, array.size());
            PRINT(array);
        }
        else if(str[0] == "BENCHMARK") {
            int size = stoi(str[2]);
            int max = stoi(str[3]);
            array = generateRandom(size, max);
            clock_t t1, t2;
            t1 = clock();
            insertionSort(array);
            //quickSort(array, 0, array.size());
            t2 = clock();
            float diff((float)t2-(float)t1);
            cout<<diff<<endl;
            
        }
        else if(str[0] == "PRINT" && str[1] == "INPUT") {
            num = stoi(str[2]);
        }
        else {
            for(int i = 0; i < num; i++) {
                arr.push_back(stoi(str[i]));
            }
            PRINT(arr);
            arr = insertionSort(arr);
            //quickSort(arr, 0, arr.size());
            PRINT(arr);
            
            
        }
        
        
    }
    
    
    
}
