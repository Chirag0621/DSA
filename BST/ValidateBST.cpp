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
void printpath(vector<int> path){
    for(int i=0;i<path.size();i++){
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
void helper(node* root,vector<int> path){
    path.push_back(root->data);

    if(root->left==NULL && root->right==NULL){
        printpath(path);
        path.pop_back();
        return;

    }
    helper(root->left,path);
    helper(root->right,path);
}
void rootToleaf(node* root){
    vector<int> path;
    helper(root,path);
}
bool validatehelper(node* root,node* min,node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data < min->data){
        return false;
    }
    if(max!=NULL && root->data > max->data){
        return false;
    }
    return validatehelper(root->left,min,root)&&
    validatehelper(root->right,root,max);
}
bool validateBST(node* root){
    return validatehelper(root,NULL,NULL);
}

int main(){
    int arr[9]={8,5,3,1,4,6,10,11,14};
    node* root= buildBST(arr,9);
    root->data=15;
    // inorder(root);
    // printinrange(root,5,12);
    // cout<<endl;
    // rootToleaf(root);
    cout<<validateBST(root);

    return 0;
}