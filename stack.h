#pragma once
#include <stack>
using namespace std;
template <typename T = double> class Stack{
private:
    double capacity;
    double occupancy = 0;
    stack <T>* data; 
public:
    Stack(int c);
    ~Stack();
    bool push(T n);
    double getcapacity();
    double getoccupancy();
    bool empty();
    int size();
    T pop();
};
template <typename T> Stack<T>::Stack(int c){
    data = new stack <T>;
    capacity = c;
}
template <typename T> Stack<T>::~Stack(){
    delete data;
}
template <typename T> bool Stack<T>::push(T n){
    if(n + occupancy > capacity){
        return false;
    }else{
            data->push(n);
            this->occupancy += n;
            return true;
    }
}
template <typename T> T Stack<T>::pop(){
    T d;
    if(!data->empty()){
        d = data->top();
        data->pop();
    }
    return d;
}
template <typename T> double Stack<T>::getcapacity(){
    return capacity;
}
template <typename T> double Stack<T>::getoccupancy(){
    return occupancy;
}
template <typename T> bool Stack<T>::empty(){
    return data->empty();
}
template <typename T> int Stack<T>::size(){
    return data->size();
}