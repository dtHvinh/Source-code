#include<iostream>
#include<stack>
#include<math.h>

using namespace std;

/*string binary(int n){
    stack<int>st;
    string res = "";
    while (n!=0){
        int e = n%2;
        st.push(e);
        n/=2;
    }
    while (!st.empty()){
        res += st.top()+'0';
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
int numberOfBits(int n) {
	return log2(n) + 1;
}
int concatenatedBinary(int n){
    int res = 0;
    for(int i=1;i<=n;i++){
        res = res*pow(10,numberOfBits(i)) + binary(i);
    }
    return res;
} */ 

int main(){
    char x=1;
    char y=5;
    if(x&y) cout<<"2";
}

