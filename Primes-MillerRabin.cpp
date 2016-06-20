//
//  main.cpp
//  hw2
//
//  Created by ZHENGLEI on 2/2/16.
//  Copyright © 2016 86. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <random>
using namespace std;

class isPrime{
private:
    
public:
    isPrime(){}
    
    unsigned long long makeRandom(unsigned long long n) {
        default_random_engine generator;
        uniform_int_distribution<unsigned long long> rnd(2,n);
        return rnd(generator);
    }
    
    unsigned long long powermod(unsigned long long a,unsigned long long n,unsigned long long m){
        unsigned long long prod = 1;
        while(n>0){
            if(n%2 != 0)
                prod = prod*a % m;
            n = n/2;
            a = a*a % m;
        }
        return prod;
    }
    bool RabinMiller(unsigned long long n, int k){
        unsigned long long a, x, d, s =0;
        bool tonextloop = 0;
        for(d = n-1; (d&1) == 0; d = d/2)
            s++;
        for(int i = 0; i<k; i++){
            a = makeRandom(n-2);
            x = powermod(a,d,n);
            if(x == 1 || x == n-1)
                continue;
            for(int i = 0; i<s; i++){
                x = x*x % n;
                if(x == 1)
                    return false;
                if(x == n-1){
                    tonextloop = 1;
                    break;
                }
            }
            if(tonextloop == 1)
                continue;
            return false;
        }
        return true;
    }
};

int main() {
    isPrime a;
    ifstream f("hw2.dat");
    int n;
    while(!f.eof()){
        f>>n;
        cout << n << '\t';
        if (a.RabinMiller(n,10))
            cout << "TRUE" <<'\n';
        else
            cout << "FALSE" <<'\n';
    }
//     cout << a.powermod(3,30,31);
}