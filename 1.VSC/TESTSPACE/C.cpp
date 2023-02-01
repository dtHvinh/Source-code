#include<iostream>
#include<stack>
#include<math.h>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<map>
#include<unordered_map>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;


vector<int> addToArrayForm(vector<int>& nums, int k) {
    int i = nums.size()-1;
    while(k != 0 && i>= 0){
        int r = k % 10 + nums[i];
        nums[i] = r % 10;
        k /= 10;
        k += r/10;
        i--;
    }
    while(k){
        nums.insert(nums.begin(),k % 10);
        k/=10;
    }
    return nums;
}

int main(){
    vector<int>nums = {2,3};
    int k = 99;
    vector<int>res = addToArrayForm(nums,k);
    for(auto i : res) cout<< i << " ";
}



