#include<iostream>
#include<queue>
using namespace std;

class Student{ // "<"overload
public:
    string name;
    int marks;

    Student(string name,int marks){
        this->name=name;
        this->marks=marks;
    }
    bool operator < (const Student &obj) const{
        return this->name < obj.name;
    }


};
int main(){
    priority_queue<Student> pq;
    pq.push(Student("aman",33));
    pq.push(Student("ayush",50));
    pq.push(Student("Karan",100));
    while(!pq.empty()){
        cout<<" top ="<< pq.top().name<<","<<pq.top().marks<<endl;
        pq.pop();

    }
    return 0;

}