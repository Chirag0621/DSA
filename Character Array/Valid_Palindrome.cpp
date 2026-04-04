#include <iostream>
using namespace std;
int main()
{
    char word[]="racefcar";
    int st=0, end=6;
    while(st<end){
        if(word[st]!=word[end]){
            cout<<"Not a valid Palindrome";
            return 0;
        }
        else{
            st++;
            end--;
        }
    }
    cout<<"Valid Palindrome";
    return 1;
}