#include<iostream>
using namespace std;
int pivot(int *arr,int n,int target){
    int left=0;
    int right=n-1;
    while(left < right){
        int mid=(left+right)/2;
        if(arr[mid]>arr[right]){
            left=mid +1;
            int k=left;
        }
        else{
            right=mid;
        }
    }

}
int main(){
    int arr[]={4,5,6,7,0,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=0;
    cout<<pivot(arr,n,target);
}