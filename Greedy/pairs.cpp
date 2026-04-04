#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool compare(pair<int,int> p1,pair<int,int> p2){
    // return p1.second<p2.second;//ascending-end
    return p1.second>p2.second;//descending-end;

    // return p2.first<p2.first;//ascending-start
    // return p1.first>p2.first;//descending-start

}
int main(){
    vector<int> start={0,1,3};
    vector<int> end={9,2,4};

    vector<pair<int,int>> act(3,make_pair(0,0));
    act[0]=make_pair(0,9);
    act[1]=make_pair(1,2);
    act[2]=make_pair(3,4);
    for(int i=0;i<act.size();i++){
        cout<<"A" <<i<<": "<<act[i].first<<","<<act[i].second<<endl;
    }
    cout<<"------------After sorting-------------"<<endl;
    sort(act.begin(),act.end(),compare);

    for(int i=0;i<act.size();i++){
        cout<<"A" <<i<<": "<<act[i].first<<","<<act[i].second<<endl;
    }
    return 0;
}