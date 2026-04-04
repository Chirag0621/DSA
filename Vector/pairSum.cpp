#include<iostream>
#include<vector>
using namespace std;
void pairsum(vector<int> arr,int target){
    int st=0, end=0;
    int currsum=0;
    vector<int> ans;
    while( st<end){
        currsum= arr[st]+arr[end];
        if(currsum==target){
            ans.push_back(st);
            ans.push_back(end);
        }
        else if(currsum>target){
            end--;
        }
        else{
            st++;
        }
    }
}
int main(){
    vector<int> arr={2,7,11,15};
    int target=9;
    pairsum(arr,target);
    return 0;
}