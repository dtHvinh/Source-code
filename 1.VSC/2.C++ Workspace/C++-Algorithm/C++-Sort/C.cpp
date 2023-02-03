#include<iostream>
#include<vector>

using namespace std;

int Pivot(vector<int>nums, int s , int e){
    int mid  = (s + e)/2;
    return nums[mid];
}

int Change(vector<int>&nums, int s, int e ,int pivot){
    int l = s;
    int r = e;
    if(l <= r){
        while( nums[l] < pivot) l++;
        while( nums[r] > pivot) r--;
        if( l < r) swap( nums[l] , nums[r]);
    }
    return l;
}


void quickSort(vector<int>&nums , int s , int e){
    if(e - s == 1) return;
    if(e - s == 2){
        if( nums[e] < nums[s] ) swap(nums[e] , nums[s]);
        return;
    }

    int t = Pivot(nums,s,e);
    int k = Change(nums, s , e , t);
    quickSort(nums, s, k-1);
    quickSort(nums, k ,e);
}




int main(){
    vector<int>nums = {3,4,2,5,1,6};
    quickSort(nums, 0 , nums.size()-1);
    for(auto i : nums) cout<<i<<" ";

}