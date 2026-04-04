#include<iostream>
using namespace std;
class parent{
    public:
    void show(){
        cout<<"Parent class show..\n";
    }
};
class child:public parent{
    public:
    void show(){
        cout<<"Child class show..\n";
    }
};
int main(){
    child child1;
    child1.show();\
    parent parent1;
    parent1.show();
    return 0;
}