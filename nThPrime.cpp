#include<iostream>
#include<math.h>
using namespace std;

bool isPrime(int n) {
    if(n == 1) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    if(n % 2 == 0) {
        return false;
    }
    for(int i = 3; i <= sqrt(n); i += 2) {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}

int nThPrime(int n) {
    int x = 1;
    int p = 3;
    int res = 0;
    if (n == 1) {
        return 2;
    }
    while(x < n) {
        if(isPrime(p)) {
            res = p;
            x++;
        }
        p += 2;
    }
    return res;
}
int main() {
    int x;
    while(true) {
        cout << "Please input a number: " << '\n';
        cin >> x;
        cout << nThPrime(x) << '\n';
        
    }
}
