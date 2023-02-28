#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int Pivot(vector<int>nums, int s , int e){
    int mid  = (s + e)/2;
    return nums[mid];
}

int Partition(vector<int>&nums, int s, int e ,int pivot){
    int l = s;
    int r = e;
    while(l <= r){
        while( nums[l] < pivot) l++;
        while( nums[r] > pivot) r--;
        if( l <= r){
            swap( nums[l] , nums[r]);
            l++;
            r--;
        }
    }
    return l;
}


void quickSort(vector<int>&nums , int s , int e){
    if(s >= e) return;
    int t = Pivot(nums,s,e);
    int k = Partition(nums, s , e , t);
    quickSort(nums, s, k-1);
    quickSort(nums, k+1 ,e);
}




int main(){
    vector<int>nums={3,4,6,2,7,8,5,9,1};
    quickSort(nums,0,nums.size()-1);
    for(auto i: nums) cout<<i<<" ";
}