#include<iostream>

#include<deque>
using namespace std;
class queue{
    deque<int> deq;
public:
    void push(int val){
        deq.push_back(val);
    }
    void pop(){
        if(!deq.empty()){
            deq.pop_front();
        }
        else{
            cout<<" Queue is empty"<<endl;
        }
    }
    int front(){
        return deq.front();
    }
    bool empty(){
        return deq.empty();
    }
};
int main(){
    queue q;
    for(int i=1;i<=5;i++){
        q.push(i);
    }
    for(int i=1;i<=5;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
