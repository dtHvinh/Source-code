#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

int Pivot(vector<int>nums, int s , int e){
    int mid  = (s + e)/2;
    return nums[mid];
}

int Change(vector<int>&nums, int s, int e ,int pivot){
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
    int k = Change(nums, s , e , t);
    quickSort(nums, s, k-1);
    quickSort(nums, k ,e);
}




int main(){
    vector<int>nums;
    ifstream a("D:/Code/Document/DataForSort.txt");
    int num;
    while(a >> num){
        nums.push_back(num);
    }
    quickSort(nums,0,nums.size()-1);
    for(auto i : nums) cout<<i<<" ";
}