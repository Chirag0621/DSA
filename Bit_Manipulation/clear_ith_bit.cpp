#include<iostream>
using namespace std;
int clear(int num, int idx){
    int bitmask= 1<<idx;
    return (num & ~bitmask);
}
int main(){
    int num = 6; // binary: 101
    int idx = 1; // index of bit to clear
    cout << "Clearing bit at index " << idx << " in " << num;
    cout << " gives " << clear(num, idx) << endl;
    return 0;
}