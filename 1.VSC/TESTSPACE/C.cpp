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

class person{
    public:
        void sayA(){
            cout<<"AAAAAA";
        }
        virtual void sayB(){};
};

class bad_person : public person{
    public:
        void sayB() override {
            cout<<"BBBBBB";
        }
};


int main(){
    bad_person a;
    a.sayB();
}



