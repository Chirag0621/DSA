#include <iostream>
#include <vector>
#include <string>
using namespace std;

class node
{
public:
    string key;
    int val;
    node *next;

    node(string key, int val)
    {
        this->key = key;
        this->val = val;
        next = NULL;
    }
    ~node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};
class HashTable
{
    int totsize;
    int currSize;
    node **table;

    int hashFuncton(string key)
    {
        int idx = 0;
        for (int i = 0; i < key.size(); i++)
        {
            idx = idx + (key[i] * key[i]) % totsize;
        }
        return idx % totsize;
    }
    void rehash()
    {
        node **oldtable = table;
        int oldsize = totsize;

        totsize = 2 * totsize;
        currSize = 0;
        table = new node *[totsize];
        for (int i = 0; i < totsize; i++)
        {
            table[i] == NULL;
        }

        for (int i = 0; i < oldsize; i++)
        {
            node *temp = oldtable[i];
            while (temp != NULL)
            {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            if (oldtable[i] != NULL)
            {
                delete oldtable[i];
            }
        }
        delete[] oldtable;
    }

public:
    HashTable(int size)
    {
        totsize = size;
        currSize = 0;

        table = new node *[totsize];

        for (int i = 0; i < totsize; i++)
        {
            table[i] = NULL;
        }
    }
    void insert(string key, int val)
    {
        int idx = hashFuncton(key);
        node *newnode = new node(key, val);
        node *head = table[idx];

        newnode->next = table[idx];
        table[idx] = newnode;

        currSize++;

        double lamda = currSize / (double)totsize;
        if (lamda > 1)
        {
            rehash();
        }
    }

    bool exists(string key)
    {
        int idx = hashFuncton(key);

        node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    int search(string key)
    {
        int idx = hashFuncton(key);

        node *temp = table[idx];
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->val;
            }
            temp = temp->next;
        }
        return -1;
        ;
    }
    void remove(string key)
    {
        int idx = hashFuncton(key);
        node *temp = table[idx];
        node *prev = temp;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if(prev==temp){
                    table[idx]=temp->next;

                }
                else{
                    prev->next=temp->next;
                }
                break;
            }
            prev=temp;
            temp=temp->next;
        }
    }
    void print()
    {
        for (int i = 0; i < totsize; i++)
        {
            cout << "idx" << i << "->";
            node *temp = table[i];
            while (temp != NULL)
            {
                cout << "(" << temp->key << "," << temp->val << ")->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};
int main()
{
    HashTable ht(5);
    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("US", 50);
    ht.insert("Nepal", 10);
    ht.insert("UK", 20);
    if (ht.exists("Nepal"))
    {
        cout << "Nepal population:" << ht.search("Nepal") << endl;
    }
    ht.print();
    ht.remove("China");
    cout<<"--------------------------"<<endl;
    ht.print();
    return 0;
}