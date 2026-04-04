#include<iostream>
using namespace std;
void SpiralMatrix(int mat[][4],int n,int m){
    int srow=0,scol=0;
    int erow=n-1,ecol=n-1;
    while(srow<=erow && scol<=ecol){
        //top
        for(int i=scol;i<=ecol;i++){
            cout<<mat[srow][i]<<" ";
        }
        //Right
        for(int i=srow+1;i<=erow;i++){
            cout<<mat[i][ecol]<<" ";
        }

        //Bottom
        for(int i=ecol-1;i>=scol;i--){
            if(srow==erow){
                break;
            }
            cout<<mat[erow][i]<<" ";
        }
        for(int i= erow-1;i>srow;i--){
            if(scol==erow){
                break;
            }
            cout<<mat[i][scol]<<" ";
        }
        srow++;
        scol++;
        erow--;
        ecol--;
    }

}
int main(){
    int mat[][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    int n=4;
    int m=4;
    SpiralMatrix(mat,n,m);
}