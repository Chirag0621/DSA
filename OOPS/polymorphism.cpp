#include<iostream>
using namespace std;
class show{
    public:
    void print(int n) {
        cout<<"int :"<< n << endl;
    }
    void print( string str){
        cout<<"string:"<<str<<endl;
    }
};
int main(){
    show s;
    s.print(25);
    s.print("hello");
    return 0;
}