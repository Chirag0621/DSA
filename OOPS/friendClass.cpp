#include<iostream>
using namespace std;
class A{
    private:
    string secret="Secret Data";
    friend class B;

};
class B{
    public:
    void showsecret(A &obj){
        cout<<obj.secret<<endl;
    }
};
int main(){
    A obj;
    B obj2;
    obj2.showsecret( obj );
    return 0;

}