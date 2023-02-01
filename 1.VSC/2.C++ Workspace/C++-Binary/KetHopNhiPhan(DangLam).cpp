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

int numberOfBits(int n) {
	return log2(n) + 1;
}

int concatenatedBinary(int n){
    int res = 0;
    for(int i=1;i<=n;i++){
        res = res*pow(10,numberOfBits(i)) + binary(i);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<binary(n);
}