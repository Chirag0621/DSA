#include<iostream>
using namespace std;
int gridWays(int r,int c,int n, int m){
    if(r==n-1 && c==m-1){
        return 1;
    }
    if(r>=n || c>=m){
        return 0;
    }
    
    // Right ways
    int val1=gridWays(r,c+1,n,m);
    // Down ways
    int val2=gridWays(r+1,c,n,m);
    
    int ans= val1+val2;
    return ans;
}
int main(){
    int n=3,m=3;
    cout<<"No. of ways to reach destination: "<< gridWays(0,0,n,m)<<endl;
    return 0;
}