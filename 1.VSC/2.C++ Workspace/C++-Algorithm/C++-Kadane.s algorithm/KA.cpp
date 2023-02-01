#include<iostream>
#include<vector>

using namespace std;

//          Calculate max sum of contiguous subaray


//          Maximum subarray sum in non circular array
int max(vector<int>vt){
    int max;
    int cur;
    for(auto i : vt){
        cur += i;
        if(i < 0) cur = 0;
        if(cur > max) max = cur;
    }
    return max;
}
//          Maximum subarray sum in circular array
int max2(vector<int>vt){
    
}
int main(){
    vector<int>vt = {1,2,4,7,-5,-6,8,8};
    cout<<max(vt);
}

