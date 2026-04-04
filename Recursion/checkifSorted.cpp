#include<iostream>
using namespace std;
int issorted(int arr[], int n,int i) {
    if(i==n-1){
        return 1;
    }
    if(arr[i]>arr[i+1]){
        return 0;
    }
    issorted(arr,n,i+1);
}
int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    if (issorted(arr,n,i)==1){
        cout<<"Array is sorted";
    }
    else{
        cout<< " Array is not sorted";
    }
    return 0;
}