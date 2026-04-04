#include<iostream>
using namespace std;
class Solution{
    public:
    void counter(){
        static int count = 0;
        count++;
        cout<<"Count : "<<count<<endl;
    }
};
int main(){
    Solution obj;
    obj.counter();
    obj.counter();
    obj.counter();
    return 0;

}