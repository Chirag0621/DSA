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
node* insert(node* root,int val){
    if(root==NULL){
        root=new node(val);
        return root;
    }
    if(val<root->data){
        root->left=insert(root->left,val);

    }
    else{
        root->right=insert(root->right,val);
    }
    return  root;
}
node* buildBST(int *arr,int n){
    node* root=NULL;

    for(int i=0;i<n;i++){
        root=insert(root,arr[i]);
    }
    return root;
}
void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void printinrange(node* root,int start,int end){
    if(root == NULL){
        return;
    }
    if(root->data>=start && root->data<=end){
        cout<<root->data<<" ";
        printinrange(root->left,start,end);
        printinrange(root->right,start,end);
    }else if(root->data < start){
        printinrange(root->right,start,end);
    }
    else {
        printinrange(root->left,start,end);
    }
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root= buildBST(arr,9);
    // inorder(root);
    printinrange(root,5,12);
    cout<<endl;
    return 0;
}