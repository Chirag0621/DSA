#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
class node{
public:
    unordered_map<char,node*> children;
    bool endofword; 

    node(){
        endofword=false;
    }
};
class trie{
    node* root;
public:
    trie(){
        root =new node();
    }
    void insert(string key){
        node* temp=root;
        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])==0){
                temp->children[key[i]]= new node();
            }
            temp=temp->children[key[i]];
        }
        temp->endofword=true;
    }
    bool search(string key){
        node* temp=root;

        for(int i=0;i<key.size();i++){
            if(temp->children.count(key[i])){
                temp=temp->children[key[i]];
            }else{
                return false;
            }
        }
        return temp->endofword;
    }
};
int main(){
    vector<string> words={"the","a","there","their","any","thee"};
    trie t;
    for(int i=0;i<words.size();i++){
        t.insert(words[i]);
    }
    cout<<t.search("those")<<endl;
    return 0;
}