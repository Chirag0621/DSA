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
bool search(node* root,int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){
        return true;
    }
    if(root->data>key){
        return search(root->left,key);
    }
    else{
        return search(root->right,key);
    }
}
node* getIS(node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
node* delnode(node* root,int val){
    if(root==NULL){
        return NULL;
    }
    if(val<root->data){
        root->left=delnode(root->left,val);
    
    }
    else if(val>root->data){
        root->right=delnode(root->right,val);
    }
    else{
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        if(root->left==NULL || root->right ==NULL){
            return root->left=NULL?root->right:root->left;
        }
        node* is=getIS(root->right);
        root->data=is->data;
        root->right=delnode(root->right,is->data);
        return root;
    }
}
int main(){
    int arr[6]={5,1,3,4,2,7};
    node* root= buildBST(arr,6);
    inorder(root);
    cout<<endl;
    // cout<<search(root,9)<<endl;
    delnode(root,4);
    inorder(root);
    cout<<endl;
    
    return 0;
}