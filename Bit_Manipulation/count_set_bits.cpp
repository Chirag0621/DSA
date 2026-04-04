#include<iostream>
using namespace std;
int countset(int num){
    int count=0;
    while(num>0){
        int last_dig=num & 1;
        count+=last_dig;
        num=num>>1;
    }
    return count;
}
int main(){
    int num=10;
    cout<<"Number of set bits in "<<num<<" is "<<countset(num)<<endl;
    return 0;
}