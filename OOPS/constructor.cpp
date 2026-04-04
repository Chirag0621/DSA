#include<iostream>
using namespace std;
class car{
    public:
    string name;
    string color;
    

    car(string name, string color){
        this ->name=name;
        this->color=color;
    }
    
};

int main(){
    car c1("Toyota", "Red");
    car c2(c1);
    cout<<c2.name<<endl;
    cout<<c2.color<<endl;
    return 0;
}