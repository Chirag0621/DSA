#include<iostream>
#include<string>
using namespace std;
void printSubset( string str,string subset) {
    int n=str.length();

    if(n==0){
        cout<<subset<<"\n";
        return;
    }
    char ch=str[0];
    //Choice of yes
    printSubset(str.substr(1),subset+ ch);
    //Choice of no
    printSubset(str.substr(1),subset);
}
int main(){
    string str="abc";
    string subset="";
    printSubset(str,subset);
}
