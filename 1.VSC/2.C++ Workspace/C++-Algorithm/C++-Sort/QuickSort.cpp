#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int Pivot(vector<int>nums, int s , int e){
    int mid  = (s + e)/2;
    return nums[mid];
}

int Partition(vector<int>&nums, int s, int e){
    int pivot = nums[s];
    int l = s+1;
    int r = e;
    while (l <= r)
    {
        while(l <= r && nums[l] <= pivot) l++;
        while(l <= r && nums[r] >= pivot) r--;
        if(l < r){
            swap(nums[l], nums[r]);
        }
    }
    swap(nums[s], nums[r]);
    return r;
}


void quickSort(vector<int>&nums , int s , int e){
    if(s >= e) return;
    int k = Partition(nums, s , e);
    quickSort(nums, s, k-1);
    quickSort(nums, k+1 ,e);
}




int main(){
    vector<int>nums={5,1,1,2,0,0};
    quickSort(nums,0,nums.size()-1);
    for(auto i: nums) cout<<i<<" ";
}