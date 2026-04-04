#include<iostream>
using namespace std;
void checkpower(int num){
    if(!(num & (num - 1))){
        cout<<"The num is power of 2";
    }
    else{
        cout<<"The num is not power of 2";
    }
}
int main(){
    checkpower(7);
    return 0;
}
