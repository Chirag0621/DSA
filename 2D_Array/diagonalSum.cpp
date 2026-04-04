#include<iostream>
using namespace std;
int dig_sum(int mat[][4],int n,int m){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=mat[i][i];
        if(i!=n-i-1){
            sum+=mat[i][n-i-1];
        }
    }
    return sum;
}
int main(){
    int mat[][4] = {{1, 2, 3, 4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;
    int m=4;
    cout<<dig_sum(mat,n,m)<<endl;
}