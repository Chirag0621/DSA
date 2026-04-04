#include<iostream>
using namespace std;
int clear_last_ith_bit(int num,int idx){
    int bitmask=(~0)<<idx;
    return num&bitmask;
}
int main(){
    int num=15;
    int idx=2;
    cout<<clear_last_ith_bit(num,idx)<<endl;
}