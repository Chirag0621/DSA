#include<iostream>
using namespace std;
bool search(int mat[][4],int n,int m,int key){
    int i=0,j=m-1;
    while(i<n && j>=0){
        if(mat[i][j]==key){
            cout<<"Key Found at position "<<i<<","<<" "<<j;
            return true;
        }
        else if(mat[i][j]>key){
            j--;
        }
        else{
            i++;
        }
    }
    cout<<"Key Not Found";
    return false;
}
int main(){
    int mat[][4] = {{1, 2, 3, 4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;
    int m=4;
    int key=14;
    search(mat,n,m,key);
}