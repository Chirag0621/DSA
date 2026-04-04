#include<iostream>
using namespace std;
int tillingproblem(int n){
    if(n==0 || n==1){
        return 1;
    }
    return tillingproblem(n-1)+tillingproblem(n-2);
}
int main(){
    int n=3;
    cout<<"Number of ways to tile a floor of size 2x"<<n<<" is "<<tillingproblem(n)<<endl;
    return 0;
}