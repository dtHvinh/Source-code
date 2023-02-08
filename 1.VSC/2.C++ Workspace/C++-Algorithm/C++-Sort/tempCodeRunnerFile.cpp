#include <iostream>
// #include <vector>
// using namespace std;

// int Pivot(vector<int>& nums, int s, int e) {
//     int mid = (s + e) / 2;
//     return nums[mid];
// }

// int Partition(vector<int>& nums, int s, int e, int pivot) {
//     int l = s;
//     int r = e;
//     while (l <= r) {
//         while (nums[l] < pivot) l++;
//         while (nums[r] > pivot) r--;
//         if (l <= r) {
//             swap(nums[l], nums[r]);
//             l++;
//             r--;
//         }
//     }
//     return l;
// }

// void QuickSort(vector<int>& nums, int s, int e) {
//     if (s >= e) return;

//     int pivot = Pivot(nums, s, e);
//     int partitionIndex = Partition(nums, s, e, pivot);

//     QuickSort(nums, s, partitionIndex - 1);
//     QuickSort(nums, partitionIndex, e);
// }

// int main() {
//     vector<int> nums = {3, 4, 2, 5, 1, 6};

//     QuickSort(nums, 0, nums.size() - 1);

//     for (int i : nums) {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }