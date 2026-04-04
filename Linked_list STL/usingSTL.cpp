#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> ll;
    ll.push_front(4);
    ll.push_back(3);
    list<int>::iterator itr;
    for(itr=ll.begin();itr!=ll.end();itr++){
        cout<<(*itr)<<"->";
    }
    cout<<"NULL";
    return 0;
}
