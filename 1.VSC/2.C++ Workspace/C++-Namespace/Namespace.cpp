#include<iostream>

using namespace std;

namespace a1
{
    void in(){
        cout<<"DTHV";
    }
} // namespace a1

namespace a2
{
    void in(){
        cout<<"VTHD";
    }   
} // namespace a2

int main(){
    a1::in();
    return 0;
}