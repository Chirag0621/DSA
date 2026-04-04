#include<iostream>
using namespace std;
class Animal{
    public:
    string color;
    void eat(){
        cout<<"eat";
    }
    void breadth(){
        cout<<"breathes\n";
    }
};
class fish:public Animal{
    public:
    int fin;
    void fins(){
        cout<<"swim\n";
    }
};
int main(){
    fish f1;
    f1.fin=3;
    f1.fins();
    f1.breadth();
    f1.eat();
    return 0;
}