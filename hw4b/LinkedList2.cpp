#include <iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

class LinkedList {
private:
    class Node {
    public:
        int val;
        Node* next;
        Node(int v, Node* n) : val(v), next(n) {}
    };
    Node* head;
    Node* tail;
    int length;
public:
    LinkedList() : head(nullptr),tail(nullptr) {
        length = 0;
        
    }
    
    LinkedList(int initialSize, Node* head, Node* tail) : head(head), tail(tail) {
        
    }
    
    ~LinkedList() { //O(n)
        Node* q;
        for (Node* p = head; p != nullptr; p = q) {
            q = p->next;
            delete p; //O(1)
        }
    }

    
    void addEnd(int v) {
        if (head == nullptr) {
            head = new Node(v, nullptr);
            return;
        }
        Node* p;
        
        for (p = head; p->next != nullptr; p = p->next)  //O(n)
            ;
        p->next = new Node(v, nullptr);
        tail = p->next;
        length++;
        
    }
    
    void addStart(int v) { //O(1)
        head = new Node(v, head);
        length++;
    }
    void insert(int i, int v) {
        Node* p = head;
        while (i > 0) {
            if (p == nullptr)
                return;
            p = p->next;
            i--;
        }
        p->next = new Node(v, p->next);
        length++;
    }
    
    void removeEnd() {
        if (head == nullptr)
            return;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node* p;
        for (p = head; p->next->next != nullptr; p = p->next)
            ;
        p->next = tail;
        tail->next = nullptr;
        length--;
        
    }
    void removeStart() {
        if (head == nullptr)
            return;
        head = head->next;
        length--;
    }
    
    int size() const { //O(n)
        int count = 0;
        for (Node* p = head; p != nullptr; p = p->next)
            count++;
        return count;
    }
    
    int get(int i) const { // O(n)
        Node* p = head;
        for ( ; i > 0; i--, p = p->next)
            if (p == nullptr)
                throw "LinkedList index out of bounds";
        return p->val;
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
        for (int i = 0; i < length; i ++) {
            if (i == length-1) {
                cout << get(i);
            }
            else {
                cout << get(i) << ",";
            }
        }
        cout << endl;
    }

};

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
    LinkedList a;
    string line;
    int start, step, end, n, m;
    vector<string> str;
    string fileName = "HW4b.txt";
    fstream myfile(fileName.c_str());
    if(myfile.fail()) {
        cout << "Failed to open file" << endl;
    }
    while (getline(myfile, line)) {
        if (line != "OUTPUT" && line.size() > 0) {
            str = split(line, ' ');
                if(str[0] == "ADD_FRONT") {
                start = stoi(split(str[1], ':')[0]);
                step = stoi(split(str[1], ':')[1]);
                end = stoi(split(str[1], ':')[2]);
                a.ADD_FRONT(start,step,end);
            }
            else if(str[0] == "ADD_BACK") {
                start = stoi(split(str[1], ':')[0]);
                step = stoi(split(str[1], ':')[1]);
                end = stoi(split(str[1], ':')[2]);
                a.ADD_BACK(start,step,end);
            }
            else if(str[0] == "REMOVE_FRONT") {
                n = stoi(str[1]);
                a.REMOVE_FRONT(n);
                
            }
            else if(str[0] == "REMOVE_BACK") {
                m = stoi(str[1]);
                a.REMOVE_BACK(m);
            
            }
        }
        else if(line == "OUTPUT") {
            a.OUTPUT();
        }
    }
    myfile.close();
}


