//
//  hw8a.cpp
//
//  Created by EricZhang on 11/7/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

/*
 * C++ Program to Implement linear chaining HashMap with single linled list
 */
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
const int TABLE_SIZE = 128;

/*
 * HashNode Class Declaration
 */
class HashNode
{
public:
    string str;
    HashNode* next;
    HashNode(string str)
    {
        this->str = str;
        this->next = NULL;
    }
};

/*
 * HashMap Class Declaration
 */
class HashMap
{
private:
    HashNode** htable;
public:
    int collisions[15];
    HashMap()
    {
        htable = new HashNode*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            htable[i] = NULL;
        for(int i = 0; i < 15; i ++) {
            collisions[i] = 0;
        }

    }
    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            HashNode* entry = htable[i];
            while (entry != NULL)
            {
                HashNode* prev = entry;
                entry = entry->next;
                delete prev;
            }
        }
        delete[] htable;
    }
    /*
     * Hash Function
     */
    int HashFunc(string s) {
        int sum = 0;
        for(int i = 0; i < s.size(); i++){
            sum += (int)s[i]*(i+1);
        }
        return sum % TABLE_SIZE;
    }
    /*
     * Insert Element at a key
     */
    void Insert(string s)
    {
        int coll = 1;
        int hash_val = HashFunc(s);
        HashNode* prev = NULL;
        HashNode* entry = htable[hash_val];
        while (entry != NULL)
        {
            prev = entry;
            entry = entry->next;
        }
        if (entry == NULL)
        {
            entry = new HashNode(s);
            if (prev == NULL)
            {
                collisions[1]++;
                htable[hash_val] = entry;
    
            }
            else
            {
                coll ++;
                prev->next = entry;
            }
            collisions[coll]++;
        }
        else
        {
            entry->str = s;
        }
    }
    /*
     * Search Element at a key
     */
    bool Contains(string s)
    {
        int hash_val = HashFunc(s);
        HashNode* entry = htable[hash_val];
        while (entry != NULL)
        {
            if (entry->str == s)
            {
                return true;
            }
            entry = entry->next;
        }
        return false;
        
    }
};
/*
 * Main Contains Menu
 */
int main()
{
    fstream myfile;
    myfile.open("dict.dat");
    HashMap h;
    string s1,s2;
    if(myfile.fail()) {
        cout << "Failed to open file 'dict.dat'" << endl;
    }
    while(myfile.good()) {
        myfile >> s1;
        h.Insert(s1);
    }
    fstream myfile2;
    myfile2.open("hw8a.dat");
    if(myfile2.fail()) {
        cout << "Failed to open file 'hw8a.dat'" << endl;
    }

    while(myfile2.good()) {
        myfile2 >> s2;
        if(h.Contains(s2)) {
            cout << s2 << ' ' << "True" << endl;
        }
        else {
            cout << s2 << ' ' << "False" << endl;
        }
    }
    cout << endl;
    cout << "insert" << ' ' << "cout" << endl;
    for (int i = 1; i < 15; i++) {
        cout << i << ' ' << h.collisions[i] << endl;
    }
    return 0;
    
    
}
