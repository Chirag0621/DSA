#include<iostream>
using namespace std;
class student{
    public:
    //Properties
    string name;
    float cgpa;
    void getpercentage(){
        cout<<(cgpa*10)<<"%\n";
    }
    
};
int main(){
    student S1;
    S1.name="Rahul";
    S1.cgpa=8.5;
    return 0;
}