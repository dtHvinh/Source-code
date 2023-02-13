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
#include<string.h>

using namespace std;

int cal(int n){
    int res;
    while( n != 0){
        res += pow(n % 10 , 2);
        n /= 10;
    }
    return res;
}
int main(){
    int n = 2932;
    vector<int>a(4);
            int i = 3;
        while(n!=0){
            a[i] = n%10;
            n/=10;
            i--;
        }
        sort(a.begin(), a.end());
        cout<<a[0];
}



