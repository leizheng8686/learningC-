//
//  main.cpp
//  HW_GrowArray
//
//  Created by ZHENGLEI on 2/29/16.
//  Copyright © 2016 86. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class GrowArray {
private:
    int* p;
    int fsize, bsize;
    int fused, bused;
    // this should double the size of your list
    void fgrow() {
        int *temp = p;
        p = new int[fsize+fsize+bsize];
        for(int i = 0; i < fsize+bused; i++)
            p[i+fsize] = temp[i];
        fsize += fsize;
        delete []temp;
    }
    void bgrow() {
        int *temp = p;
        p = new int[fsize+bsize+bsize];
        for(int i = fsize-fused; i < fsize+bused; i++)
            p[i] = temp[i];
        bsize += bsize;
        delete []temp;
    }
public:
    GrowArray() : p(new int[2]), fsize(1), bsize(1), fused(0), bused(0) {
    }
    GrowArray(int capacity) : p(new int[capacity+capacity]), fsize(capacity), bsize(capacity), fused(0), bused(0) {
    }
    ~GrowArray() {
        delete [] p;
    }
    void ADD_FRONT(int v) { // O(   )
        if (fused == fsize)
            fgrow();
        p[fsize-fused-1] = v;
//        cout << "p[" << fsize-fused-1 << "]= " << p[fsize-fused-1] << '\n';
        fused++;
    }
    
    void ADD_BACK(int v) {  //O(    )
        if (bused == bsize)
            bgrow();
        // O(1)
        p[fsize+bused] = v;
        bused++;
    }
    void REMOVE_FRONT(int n){
        fused -= n;
    }
    void REMOVE_BACK(int n){
        bused -= n;
    }
    int getCapacity() const {
        return fsize+bsize;
    }
    
    int getUsed() const {
        return fused+bused;
    }
    int get(int i) const { //O(1)
        if (i < 0 || i >= fused+bused)
            throw "Die!";
        return p[i+fsize-fused];
    }
    void set(int i, int v) { // O(1)
        if (i < 0 || i >= fused+bused)
            throw "Die!";
        p[i+fsize-fused] = v;
    }
    
};

int main() {
    GrowArray a;
    string func;
    int num,count=0;
    ifstream f("HW4a.txt");
#if 1
    f >> func;
    while(!f.eof()){
        if(func == "ADD_FRONT"){
            f >> func;
            int fnum[20],fno=0;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                fnum[fno]=num;
                fno++;
                count++;
                f >> func;
            }
            for(int i = fno; i>0 ; i--)
                a.ADD_FRONT(fnum[i-1]);
        }
        else if(func == "ADD_BACK"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count++;
                a.ADD_BACK(num);
                f >> func;
            }
        }
        else if(func == "REMOVE_FRONT"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count -= num;
                a.REMOVE_FRONT(num);
                f >> func;
            }
        }
        else if(func == "REMOVE_BACK"){
            f >> func;
            while((func[0]<='9') && (func[0]>='0')){
                num = atoi(func.c_str());
                count -= num;
                a.REMOVE_BACK(num);
                f >> func;
            }
        }
        if(func == "OUTPUT"){
            for(int i = 0; i < count; i++)
                cout <<a.get(i)<<" ";
            cout << '\n';
            f >> func;
        }
    }
#endif
    
#if 0
    int n=999;
    char fun[256];
    f >> func;
    cout << func << '\n';
    if(func == "ADD_FRONT"){
        f >> func;
    if ((func[0]<='9') && (func[0]>='0') )
        n = atoi(func.c_str());
    cout << n << '\n';
//    for (int j = 0; j < count; j++)
//        cout << a.get(j) <<'\n';
    }
#endif
}

