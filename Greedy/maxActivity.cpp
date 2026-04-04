#include<iostream>
#include<vector>
using namespace std;
int maxActivities(vector<int> start,vector<int> end){
    //sort on end time
    //A0 selected
    int count=0;
    int currEnd=0;
    for(int i=0;i<start.size();i++){
        if(start[i]>=currEnd){ //non - overlapping condition
            count++;
            currEnd=end[i];
        }
    }
    return count;
}
int main(){
    vector<int> start={1,3,0,5,8,5};
    vector<int> end={2,4,6,7,9,9};
    cout<<"Maximum activies that can be done is "<<maxActivities(start,end)<<endl;
    return 0;
}