#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
 

    int * arr;
    public:
    SegmentTree(vector<int> &v){
        int len = 0;
        for(int i = 0; i < 64; i++ ){
            if(v.size() == 1<<i){
                len = (1<<i+1);
            }
            if(v.size() < 1<< i){
                len = (1<<i);
            }
        }
        arr = new int[len];
        
    }
    ~SegmentTree(){
        delete arr;
    }

    
};

