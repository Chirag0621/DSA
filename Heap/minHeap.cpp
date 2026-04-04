#include<iostream>
#include<vector>
using namespace std;

class Heap{
  vector<int> vec;
public:
  void push(int val){
    vec.push_back(val);

    int x=vec.size()-1;
    int parIdx=x/2;

    while(parIdx>=0 && vec[x]<vec[parIdx]){
      swap(vec[x],vec[parIdx]);
      x=parIdx;
      parIdx=(x-1)/2;
    }
  }
  void heapify(int i){
    int l=2*i+1;
    int r=2*i+2;

    int minIdx=i;
    if(l<vec.size() && vec[l]<vec[minIdx]){
      minIdx=l;
    }
    if(r<vec.size() && vec[r]<vec[minIdx]){
      minIdx=r;

    }
   
    if(minIdx!=i){
       swap(vec[i],vec[minIdx]);
      heapify(minIdx);
    }
  }
  void pop(){
    swap(vec[0],vec[vec.size()-1]);
    vec.pop_back();
    heapify(0);
  }

  int top(){
    return vec[0];
  }
  void print(){
    int n=vec.size();
    for(int i=0;i<n;i++){
      cout<<vec[i]<<" ";
    }
  }
  bool empty(){
        return vec.size()==0;
  }

};
int main(){
  Heap h;
  h.push(8);
  h.push(7);
  h.push(9);
  h.push(10);
  h.push(11);
  h.push(12);
  h.push(14);
  h.push(13);
  h.push(5);
  h.print();
  cout<<" \n\n";
  vector<int> arr;
  while(!h.empty()){
    int val=h.top();
    arr.push_back(val);
    h.pop();
  }
  for(int i=0;i<arr.size();i++){
    cout<<arr[i]<<" ";
  }
  return 0;

}