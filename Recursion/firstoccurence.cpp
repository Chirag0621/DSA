#include<iostream>
#include<vector>
using namespace std;
int occurence(vector<int> vec,int n,int i,int target){
    if(i==n){
        return -1;
    }
    if(vec[i]==target){
        return i;
    }
    return occurence( vec, n, i+1, target);
}
int main(){
    vector<int> vec={1,2,3,3,3,4,5};
    int size=vec.size();
    int i=0;
    int target=3;
    int result=occurence(vec,size,i,target);
    if(result){
        cout<<"Target Found at "<<result;
    }
    else{
        cout<<"target Not Found"<<endl;
    }
}