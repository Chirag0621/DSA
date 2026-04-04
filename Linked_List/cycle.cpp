#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = NULL;
        tail = NULL;
        
    }
    void push_front(int val)
    {
        Node *newNode = new Node(val);
        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void printList()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    int size(){
        int sz=0;
        Node* temp=head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }
    void removeNth(int sz,int n){
        Node* prev=head;
        for(int i=0;i<(sz-n);i++){
            prev=prev->next;
        }
        Node* toDel=prev->next;
        cout<<"Going to delete "<< toDel->next<<endl;
        prev->next=prev->next->next;
    }
    void iscycle(Node* head){
        bool iscycle=false;
        Node* slow=head;
        Node* fast=head;
        Node* prev=NULL;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<"Cycle exist\n";
                iscycle=true;
                break;
            }
        }
        if(!iscycle){
            cout<<"cycle does not exist\n";
            return;
        }
        slow=head;
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
            fast->next=NULL;
        }
        else{
            while(slow!=fast){
                slow=slow->next;
                prev=fast;
                fast=fast->next;
            }
            prev->next=NULL;
        }
    }
    void help(){
        Node* temp=head;
        iscycle(temp);
    }
};
int main()
{
    LinkedList ll;
    ll.push_front(5);
    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    // int sz=ll.size();
    // ll.removeNth(sz,2);
    // ll.printList(); 
    ll.help();
    ll.printList();
    return 0;
}
