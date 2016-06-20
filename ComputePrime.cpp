//
//  main.cpp
//  HWa1
//
//  Created by ZHENGLEI on 1/24/16.
//  Copyright © 2016 86. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;

int ComputePrimesNumber(unsigned long long a,unsigned long long b){
    if(a > b){
        int temp;
        b = temp;
        b = a;
        a = temp;
    }
    unsigned int nbysqrt = sqrt(b);
    unsigned int PrimesNumber = 0;
    bool *prime = new bool[nbysqrt+1];
    bool *primeab = new bool[b-a+2];
    unsigned long long b_a = b-a+2;
    
    //initialize the prime[] and kick out the even
    for(int i = 1; i < nbysqrt+1; i+=2){
        prime[i] = 1;
        prime[i-1] = 0;
    }
    prime[1]=0;
    if(nbysqrt%2==0)
        prime[nbysqrt]=0;
    if(nbysqrt>1)
        prime[2] = 1;
    
    //get the primes up to sqrt(b)
    for(int i = 3; i < nbysqrt + 1; i+=2){
        if(prime[i]==1)
            for(int j=i*i; j < nbysqrt + 1; j+=i+i)
                prime[j] = 0;
    }
//    output the primes in prime[]
//    for(int i = 1; i < nbysqrt + 1; i++){
//        if(prime[i]==1)
//            cout << i << '\n';
//    }
    
    //initialize the prime[] and kick out the even
    if(a%2==0)
        for(int i = 1; i < b_a; i+=2){
            primeab[i] = 0;
            primeab[i-1] = 1;
        }
    else
        for(int i =1; i < b_a; i+=2){
            primeab[i] = 1;
            primeab[i-1] = 0;
        }
    primeab[0] = 0;
    if(b%2==0)
        primeab[b_a-1]=0;
    
    long long beginnumber;
    for(int i = 1; i < nbysqrt + 1; i+=2){
        if(prime[i]==1){
            beginnumber = a+i-a%i;
            for(long long n = beginnumber-a+1; n < b_a; n+=i)
                primeab[n] = 0;
        }
    }
//  in case a<nbysqrt
    for(long long i = a; i < nbysqrt+1; i++)
        if(prime[i]==1)
            primeab[i-a]=1;
    if(a==1)
        primeab[0] = 0;

    
//    for(long long i = a,n = 0;i<b+1;i++,n++)
//        if(primeab[n]==1)
//            cout << i <<'\n';

    for(int i = 0; i < b_a; i++)
        PrimesNumber+=primeab[i];
    
    delete []prime;
    delete []primeab;
    return PrimesNumber;
}

int main() {
    // insert code here...
    unsigned long long a,b;
    cout << "Please type two numbers:\n";
    cin >> a >> b;
    cout << ComputePrimesNumber(a, b) << '\n';
    return 0;
}
