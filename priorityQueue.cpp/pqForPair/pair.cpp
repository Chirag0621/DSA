#include<iostream>
#include<queue>
using namespace std;
struct  ComparePair{
    bool operator()(pair<string,int> &p1,pair<string,int> p2){
        return p1.second>p2.second;//min heap condition
    }
};


int main(){
    priority_queue<pair<string, int>,vector<pair<string,int>>,ComparePair> pq;

   pq.push(make_pair("aman",33));
    pq.push(make_pair("ayush",50));
    pq.push(make_pair("Karan",100));
    // for max heap
    while(!pq.empty()){
        cout<<" top ="<< pq.top().first<<","<<pq.top().second<<endl;
        pq.pop();
    }
    return 0;
}