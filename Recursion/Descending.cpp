#include<iostream>
using namespace std;
void desc(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    desc(n-1);
}
int main(){
    int n=5;
    desc(n);
    return 0;
}