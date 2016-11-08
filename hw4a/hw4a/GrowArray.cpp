//
//  GrowArray.cpp
//  hw4a
//
//  Created by EricZhang on 10/8/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;


class GrowArray {
private:
    int* data;
    int size;
public:
    GrowArray() {
        data = nullptr; // O(1)
        size = 0;
    }
    GrowArray(int initialSize) {
        data = new int[initialSize]; //O(1)
        size = initialSize;
    }
    ~GrowArray() {
        delete [] data;
    }
    void addEnd(int v) {   //O(n)
        int* temp = data; // O(1)
        
        data = new int[size+1]; // O(1)
        for (int i = 0; i < size; i++) //O(n)
            data[i] = temp[i];
        data[size] = v;
        size++;
    }
    void addStart(int v) { //O(n)
        int* temp = data;
        data = new int[size+1];
        for (int i = 0; i < size; i++) //O(n)
            data[i+1] = temp[i];
        data[0] = v;
        size++;
    }
    void removeEnd() { //O(1)
        size--;
    }
    void removeStart() { //O(n)
        for (int i = 0; i < size-1; i++)
            data[i] = data[i+1];
        size--;
    }
    int get(int i) {
        return data[i];
    }
    void ADD_FRONT(int start, int step, int end) {
        for (int i = start; i <= end; i += step) {
            addStart(i);
        }
    }
    void ADD_BACK(int start, int step, int end) {
        for (int i = start; i <= end; i += step) {
            addEnd(i);
        }
    }
    void REMOVE_FRONT(int n) {
        for (int i = 0; i < n; i ++) {
            removeStart();
        }
    }
    void REMOVE_BACK(int m) {
        for (int i = 0; i < m; i ++) {
            removeEnd();
        }
    }
    void OUTPUT() {
        for (int i = 0; i < size; i ++) {
            if (i == size-1) {
                cout << data[i];
            }
            else {
                cout << data[i] << ",";
            }
        }
        cout << endl;
    }
};
//split string
void split(const string &s, char delim, vector<string> &elems) {
    stringstream ss;
    ss.str(s);
    string item;
    while (getline(ss, item, delim)) {
        if (!item.empty()) elems.push_back(item);
    }
}

//return splitted string to a vector
vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}


int main() {
    GrowArray a;
    string line;
    int start, step, end, n, m;
    vector<string> str;
    string fileName = "HW4a.txt";
    fstream myfile(fileName.c_str());
    if(myfile.fail()) {
        cout << "Failed to open file" << endl;
    }
    while (getline(myfile, line)) {
        //getline(myfile, line);
        //myfile >> line;
        if (line != "OUTPUT" && line.size() > 0) {
            str = split(line, ' ');
            //cout << str[0] << "," << str[1] << endl;
            if(str[0] == "ADD_FRONT") {
                start = stoi(split(str[1], ':')[0]);
                step = stoi(split(str[1], ':')[1]);
                end = stoi(split(str[1], ':')[2]);
                a.ADD_FRONT(start,step,end);
                cout << endl;
            }
            else if(str[0] == "ADD_BACK") {
                start = stoi(split(str[1], ':')[0]);
                step = stoi(split(str[1], ':')[1]);
                end = stoi(split(str[1], ':')[2]);
                a.ADD_BACK(start,step,end);
                cout << endl;
            }
            else if(str[0] == "REMOVE_FRONT") {
                n = stoi(str[1]);
                a.REMOVE_FRONT(n);
                cout << endl;
            }
            else if(str[0] == "REMOVE_BACK") {
                m = stoi(str[1]);
                a.REMOVE_BACK(m);
                cout << endl;
            }
        }
        else if(line == "OUTPUT") {
            a.OUTPUT();
            cout << endl;
        }
    }
    myfile.close();
}







