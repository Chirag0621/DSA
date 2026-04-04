#include<iostream>
using namespace std;
class complex{
    int real;
    int imaginary;
    public:

    complex(int r,int i){
        real=r;
        imaginary=i;
    }
    void shownum(){
        cout<< real<<"+"<<imaginary<<"i\n";
    }
    complex operator +(const complex &other)const{
        int resReal = real - other.real;
        int resImg = imaginary - other.imaginary;
        return complex(resReal, resImg);
    }
};
int main(){
    complex c1(5,6);
    complex c2(3,4);
    c1.shownum();
    c2.shownum();
    complex c3 = c1+(c2);
    cout << "c1 - c2 = ";
    c3.shownum();
    return 0;
}