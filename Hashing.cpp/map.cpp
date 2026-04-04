#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;


int main(){
    //key value pair
    map<string,int> map;

    map["China"]=150;
    map["India"]=150;
    map["US"]=50;
    map["Nepal"]=10;

    for(pair<string,int> country:map){
        cout<<country.first<<","<<country.second<<endl;
    }
    map.erase("Nepal");
    //count->0,1
    if(map.count("Nepal")){
        cout<<"Nepal exist"<<endl;
    }
    else{
        cout<<"Nepal doesn't Exist";
    }
    return 0;

}