#include<iostream>
#include<vector>
using namespace std;
class heap{
    vector<int> vec;
public: 
    void push(int val){
        vec.push_back(val);

        int x=vec.size()-1;
        int parIdx= (x-1)/2;

        while(parIdx >=0 && vec[x]>vec[parIdx]){
            swap(vec[x],vec[parIdx]);
            x= parIdx;
            parIdx=(x-1)/2;
                
        }
    }
    void pop(){

    }
    int top(){
        return vec[0];
    }
    bool empty(){
        return vec.size()==0;
    }
};
int main(){
    heap h;
    h.push(8);
    h.push(4);
    h.push(5);
    cout<<h.top();
}