#include<iostream>
using namespace std;
int set(int num,int idx){
    return (num | (1 << idx));
}
int main(){
    int num = 6;
    int idx = 3;
    cout << set(num,idx) << endl;
}