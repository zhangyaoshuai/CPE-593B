//hw: trie
// Author: Lin Zhu
#include <iostream>
#include <string>
#include<fstream>
using namespace std;
class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        for(int i = 0; i < 26; i++)
            next[i] = nullptr;
        isString = false;
    }
    TrieNode *next[26];
    bool isString;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    private:
    TrieNode* root;
};
// Inserts a word into the trie.
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

// Returns if the word is in the trie.
bool search(TrieNode* root,string word) {
    TrieNode *p = root;
    for(int i = 0; i < word.size(); i++)
    {
        if(p == NULL)
        {
            cout << "false\n";

            return false;
                    }
        p =  p->next [word[i]-'a'];
    }
    if(p == NULL || p->isString == false)
    {
        cout << "false\n";
        return false;
       
    }
    cout << "true\n";
    return true;
    
}

int main(){
    ifstream myfile;
    myfile.open("/Users/Eric/Documents/CPE593/HW6a/HW6a/dict.txt");
    if (myfile.fail())
    {
        cout << "Read file fail!!!" << endl;
        return -1;
    }
    TrieNode* root=new TrieNode();
    string s="hello";
    while(!myfile.eof()){
        myfile>>s;
        insert(root,s);
    }
    myfile.close();
    myfile.open("/Users/Eric/Documents/CPE593/HW6a/HW6a/HW6a.txt");
    if (myfile.fail())
    {
        cout << "Read file fail!!!" << endl;
        return -1;
    }
    while(!myfile.eof()){
        myfile>>s;
        cout << s<< "\n";
        search(root,s);
    }
    
    return 0;
}
