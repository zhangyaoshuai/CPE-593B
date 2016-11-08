//
//  hw6a_trie.cpp
//  HW6a
//
//  Created by EricZhang on 10/24/16.
//  Copyright © 2016 Apple.Inc. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class TrieNode {
public:
    TrieNode *next[26];
    bool isString;
    TrieNode() {
        for(int i = 0; i < 26; i++)
            next[i] = nullptr;
        isString = false;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
private:
    TrieNode* root;
};

void insert(TrieNode* root,string word) {
    TrieNode *p = root;
    for(int i = 0; i < word.size(); i++){
        if(p->next[word[i]-'a'] == nullptr){
            p->next[word[i]-'a'] = new TrieNode();
        }
        p = p->next[word[i]-'a'];
    }
    p->isString = true;
}


bool search(TrieNode* root,string word) {
    TrieNode *p = root;
    for(int i = 0; i < word.size(); i++)
    {
        if(p == NULL)
        {
            cout << "NO\n";
            
            return false;
        }
        p =  p->next [word[i]-'a'];
    }
    if(p == NULL || p->isString == false)
    {
        cout << "NO\n";
        return false;
        
    }
    cout << "YES\n";
    return true;
    
}

int main(){
    ifstream myfile;
    myfile.open("dict.txt");
    if (myfile.fail())
    {
        cout << "Read file fail!!!" << endl;
    }
    TrieNode* root=new TrieNode();
    string s;
    while(myfile.good()){
        myfile>>s;
        insert(root,s);
    }
    myfile.close();
    string line;
    myfile.open("HW6a.txt");
    if (myfile.fail())
    {
        cout << "Read file fail!!!" << endl;
    }
    while(getline(myfile, line)){
        cout << line << " ";
        search(root,line);
    }
    return 0;
}
