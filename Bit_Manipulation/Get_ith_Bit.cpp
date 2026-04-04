#include<iostream>
using namespace std;
int get(int num,int idx){
    int bitmask= 1<<idx;
    if(!(num &bitmask)){
        return 0;
    }
    else{
        return 1;
    }
}
int main(){
    int num=5;
    int idx=1;
    cout<<get(num,idx)<<endl;
}