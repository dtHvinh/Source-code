#include <iostream>
#include <string>
#include <stack>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(),nums.end());
    int closet = nums[0]+nums[1]+nums[2];
    if(nums.size()==3) return closet;
    for(int left = 0 ; left<nums.size()-2 ; left++){
        int mid = left+1;
        int right = nums.size()-1;
        while(mid < right){
            int curSum = nums[left]+nums[mid]+nums[right];
            if(curSum == target) return curSum;
            if(abs(curSum - target) < abs(closet - target)) closet = curSum;
            if(curSum > target) right--;
            else mid++;
        }
    }
    return closet;
}
int calculate(string a){
    a += '@';
    stack<int>st;
    int curNum = 0; 
    int res = 0;      
    int sigh = 1;    
    for(int i = 0 ; i < a.size() ; i++){
        if(a[i] >= '0' && a[i] <= '9'){
            curNum = curNum*10 + a[i] -'0';  
        }
        else{
            res += sigh * curNum;
            curNum = 0;
            if( a[i] == '-') sigh = -1;
            if( a[i] == '+') sigh = 1;
            if( a[i] == '('){
                st.push(res);
                st.push(sigh);
                res = 0; sigh = 1;
            }
            if( a[i] == ')'){
                res *= st.top();st.pop();
                res += st.top();st.pop();
            }
        }
    }
    return res;
}