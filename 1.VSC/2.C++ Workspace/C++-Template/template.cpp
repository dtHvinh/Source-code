#include<iostream>
#include<vector>

template<typename T>
T find_max(T arg) {
    return arg;
}

template<typename T, typename... Args>
T find_max(T arg, Args&&... args) {
    T max_rest = find_max(std::forward<Args>(args)...);
    return (arg > max_rest) ? arg : max_rest;
}

int main(){

}