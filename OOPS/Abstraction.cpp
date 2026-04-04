#include<iostream>
using namespace std;
class shape{
    public:
    void draw(){
        cout<<"we are drawing a shape"<<endl;

    }
};
class circle: public shape{
    draw();
};
class square: public shape{
    draw();
};