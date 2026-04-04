#include<iostream>
#include<vector>
using namespace std;
class node{
public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data=data;
        left=right=NULL;
    }
};
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void getinorder(node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }
    getinorder(root->left,nodes);
    nodes.push_back(root->data);
    getinorder(root->right,nodes);
}
node* buildBSTvec(vector<int> &arr,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    node* curr= new node(arr[mid]);
    curr->left= buildBSTvec(arr,st,mid-1);
    curr->right=buildBSTvec(arr,mid+1,end);
    return curr;
}
node* mergeBST(node* root1,node* root2){
    vector<int> nodes1;
    vector<int> nodes2;
    vector<int> merged;

    getinorder(root1,nodes1);
    getinorder(root2,nodes2);
    int i=0,j=0;
    while(i<nodes1.size() && j<nodes2.size()){
        if(nodes1[i]<nodes2[j]){
            merged.push_back(nodes1[i++]);
        }
        else{
            merged.push_back(nodes2[j++]);
        }
    }
    while(i<nodes1.size()){
        merged.push_back(nodes1[i++]);
    }
    while(j<nodes2.size()){
        merged.push_back(nodes2[j++]);
    }
    return buildBSTvec(merged,0,merged.size()-1);
}

int main(){
    node* root1=new node(2);
    root1->left=new node(1);
    root1->right=new node(4);

    node* root2= new node(9);
    root2->left=new node(3);
    root2->right= new node(12);

    node* root= mergeBST(root1,root2);
    preorder(root);
    cout<<endl;
    return 0;

}