#include <iostream>
using namespace std;
void Uptolow(char *word,int n){
    for(int i=0;i<n;i++){
        char ch=word[i];
        if(ch>='A' && ch<='Z' ){
            cout<<ch;
            continue;
        }
        else{
            ch= ch-'a'+'A';
            cout<<ch;
        }
    }
}
int  main(){
    char word[]="Apple";
    int n=5;
    Uptolow(word,n);
    return 0;
}