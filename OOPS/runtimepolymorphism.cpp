#include<iostream>
using namespace std;
class parent {
    public:
    virtual void hello(){
        cout<<"Child hello\n";
    }
};
class child:public parent{
    public:
    void hello(){
        cout<<"Child hello\n";
    }
};
int main(){
    parent *ptr;
    ptr = new child();
    ptr->hello();
    return 0;
}