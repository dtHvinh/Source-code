#include<iostream>
#include<stack>
#include<string>
#include<cstring>
using namespace std;

int prec(char x)
{
	if (x == '(')
		return 0;
	if (x == '+' || x == '-')
		return 1 ;
	if (x == '*' || x == '/' || x == '%')
		return 2;
	return 3;
}


string infixToPostfix(string s){     //bai cua tui
    stack<char>S;
    string pos;
    for(auto i:s){
        if(i <= '9' && i >= '0') pos += i;        
        else if(i =='(') S.push(i);                          
        else if(i ==')'){                                        
            while(S.top()!='('){
                pos += S.top();
                S.pop();
            }
            S.pop();
        }
        else{                                                   
            while(!S.empty() && prec(S.top()) >= prec(i)){            //   "!S.empty" phải đặt trước prec() >= prec()       :((( hong hỉu
                pos +=S.top();
                S.pop();
            }
            S.push(i);
        }
    }
    while(!S.empty()){
        pos += S.top();
        S.pop();
    }
    return pos;
}

float calculate(float n,float m,char c){                      //Tam dung
    float res=0.0;
    switch(c){
        case '+': res = m + n; break;
        case '-': res = m - n; break;
        case '*': res = m * n; break;
        case '/': res = m / n; break;
        case '%': res = (int)m % (int)n; break;
    }
    return res;
}


float tinh(string a){
    stack<float>btht;
    for(auto i:a){
        if(i<='9' && i>='0'){
            float u = i-48;
            btht.push(u);
        }
        else{
            float m = btht.top();
            btht.pop();
            float n = btht.top();
            btht.pop();
            float t = calculate(m,n,i);
            btht.push(t);
        }
    }
    return btht.top();
}

int main()
{
    string a;
    cout<<"Input: ";
    getline(cin,a);
    string b=infixToPostfix(a);
    cout<<"Output: ";
    for(auto i:b) cout<<i<<" ";
    cout<<endl<<"Result: "<<tinh(b);
    return 0;
}