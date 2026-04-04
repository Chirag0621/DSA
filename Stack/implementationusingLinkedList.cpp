#include<iostream>
#include<list>
using namespace std;
template<class T>
class stack{
    list<T> s;
public:
    void push(T val){
        s.push_front(val);
    }
    void pop(){
        s.pop_front();
    }
    int top(){
        return s.front();
    }
    bool isEmpty(){
        return s.size()==0;
    }
};
int main(){
    
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    while(!s.isEmpty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}