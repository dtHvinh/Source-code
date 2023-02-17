#include<iostream>

template<typename T>
T add(T a, T b){
    return a + b;
}

int main(){
    float a = 5;
    float b = 5.9;
    std::cout<< add(a,b);
}