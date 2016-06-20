//
//  main.cpp
//  fill(0); HW3a - Searching
//
//  Created by ZHENGLEI on 2/15/16.
//  Copyright © 2016 86. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

void BinarySearching(int x[], int n, int key){
    int i=0, j=n-1, count=0;
    int middle=0;
    while(i<=j){
        count++;
        middle = (i+j)/2;
        if(x[middle] > key)
            j = middle-1;
        else if(x[middle] < key)
            i = middle+1;
        else
            break;
//        cout << x[middle] << '\n';
    }
    if(x[middle] == key)
        cout << x[middle] << '\t' << count << '\n';
    else
        cout << "NOT FOUND" << '\t' << count << '\n';
}

int main(int argc, const char * argv[]) {
    // insert code here...
    ifstream hw3("HW3.txt");
    hw3.seekg(6,ios::beg);
    int n, key, casenvm;
    hw3 >> casenvm;
    for(int m =0; m <casenvm; m++){
        hw3 >> n;
        int x[n];
        for(int i = 0; i<n; i++)
            hw3 >> x[i];
        hw3 >> key;
        BinarySearching(x,n,key);
    }
    return 0;
}
