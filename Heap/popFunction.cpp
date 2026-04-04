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
    void heapify(int i){
        if(i>=vec.size()){
            return;
        }
        int l=2*i+1;
        int r=2*i+2;

        int maxIdx=i;
        if(l< vec.size() && vec[l]>vec[maxIdx]){
            maxIdx=l;
        }
        if(r<vec.size() && vec[r]>vec[maxIdx]){
            maxIdx=r;
        }
        swap(vec[i],vec[maxIdx]);
        if(maxIdx!=i){
            heapify(maxIdx);
        }
    }
    void pop(){
    //step 1
    swap(vec[0],vec[vec.size()-1]);

    //step 2
    vec.pop_back();
    
    // step3
    heapify(0);//O(logn)
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
    cout<<h.top()<<endl;
    h.pop();
    while(!h.empty()){
        cout<<" top ="<<h.top()<<endl;
        h.pop();
    }
}