//
//  main.cpp
//  QuickSort
//
//  Created by ZHENGLEI on 2/7/16.
//  Copyright © 2016 86. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <random>
using namespace std;

int makeRandom(int min, int max) {
    random_device rd ;
    default_random_engine generator(rd());
    uniform_int_distribution<int> rnd(min,max);
    return rnd(generator);
}

bool QuickSort(int x[],int L,int R){
    int q = makeRandom(L, R);
    int Q = x[q];
    int i = L, j = R;
    while(i < j){
        while(x[i]<Q){
            i++;
        }
        while(x[j]>Q){
            j--;
        }
        if(i < j){
            x[i] = x[i] + x[j];
            x[j] = x[i] - x[j];
            x[i] = x[i] - x[j];
            i++;
        }
    }
    i--;
    if((i-L)>0&&(R-L)>1)
        QuickSort(x, L, i);
    if((R-i)>0&&(R-L)>1)
        QuickSort(x, i+1, R);
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream f("hw3.dat");
    int n;
    f >> n;
    int x[n]; //  int*x  =  new int[n];
    for (int i = 0; i < n; i++)
        f >> x[i];
    QuickSort(x, 0, n-1);
    for (int i = 0; i < n; i++)
        cout << x[i] << ' ';
    cout << '\n';
    return 0;
}
