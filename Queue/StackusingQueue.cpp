#include<iostream>
#include<deque>
using namespace std;
class stack{
    deque<int> deq;
public: 
    void push(int val){
        deq.push_front(val);
    }
    void pop(){
        if(!deq.empty()){
            deq.pop_front();
        }
        else{
            cout<<" Stack is empty"<<endl;
        }
    }
    int top(){
        if(!deq.empty()){
            return deq.front();
        }
        else{
            cout<<" Stack is empty"<<endl;
        }
    }
};
int main(){
    stack s;
    for(int i=1;i<=5;i++){
        s.push(i);
    }
    for(int i=1;i<=5;i++){
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}