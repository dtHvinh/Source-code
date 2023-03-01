#include<iostream>
#include<stack>
#include<math.h>
using namespace std;

int binary(int n){
    stack<int>st;
    int res = 0;
    while (n!=0){
        int e = n%2;
        st.push(e);
        n/=2;
    }
    while (!st.empty()){
        res = res*10 + st.top();
        st.pop();
    }
    return res;
}

int a2to10(int n){
    int res = 0;
    int t = (int)log10(n)+1;  
    int i=0;
    while(n>0){
        res += n%10*pow(2,i++);
        n/=10;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<binary(n);
}