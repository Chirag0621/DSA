#include<iostream>
#include<map>
using namespace std;


int main(){
    map<int,string> m;

    m[101]="Rahul";
    m[110]="Neha";
    m[102]="Rahul";
    m[101]="Rajat";

    cout<<m[101]<<endl;
    cout<<m.count(101)<<endl;
    for(auto it:m){
        cout<<"key = "<<it.first<<" , "<<" value = "<<it.second<<endl;
    }
    return 0;
}