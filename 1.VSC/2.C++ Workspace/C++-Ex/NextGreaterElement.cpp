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
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    vector<int>res(nums1.size());

    stack<int>st;

    unordered_map<int,int>map;
                                    
    /*for(int i = nums2.size()-1 ; i>= 0 ; i--){                        // Cách từ sau ra trước          

        while(!st.empty() && nums2[i] > st.top())
            st.pop();

        if(!st.empty()) map[nums2[i]] = st.top();

        st.push(nums2[i]);
    }*/


    for(int i = 0 ; i < nums2.size() ; i++){        
        while(!st.empty() and nums2[i] >= st.top()){                    // Cách từ trước ra sau
            map[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    int j = 0;

    for(auto i : nums1){
        res[j++] = (map.find(i) != map.end()) ? map[i] : -1;
    }

    return res;
}