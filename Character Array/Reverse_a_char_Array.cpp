#include<iostream>
using namespace std;
int main(){
    char word[]="CODE";
    int st=0;
    int end=3;
    while(st<end){
        swap(word[st++],word[end--]);
    }
    cout<<word;
}