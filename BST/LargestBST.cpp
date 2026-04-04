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
class Info{
public:
    bool isBST;
    int min;
    int max;
    int sz;

    Info(bool isBST,int min,int max,int sz){
        this->isBST=isBST;
        this->min=min;
        this->max=max;
        this->sz=sz;
    }
};
static int maxSize;
Info* largestBST(node* root){
    if(root ==  NULL){
        return new Info(true,INT_FAST16_MAX,INT16_MIN,0);
    }
    // if(root ==NULL){
    //     return NULL;
    // }
    // if(root->left==NULL && root->right){
    //     new Info(true,root->data,root->data,1);
    // }
    Info* leftInfo=largestBST(root->left);
    Info* rightInfo=largestBST(root->right);

    int currMin=min(root->data,min(leftInfo->min,rightInfo->min));
    int currMax=max(root->data,max(leftInfo->max,rightInfo->max));
    int currSz=leftInfo->sz+rightInfo->sz+1;

    if(leftInfo->isBST && rightInfo->isBST && root->data>leftInfo->max && root->data<rightInfo->min){
        maxSize=max(maxSize,currSz);
        return new Info(true,currMin,currMax,currSz);
    }
    return new Info(false,currMin,currMax,currSz);
    
    
    
    
}

int main(){
    node* root = new node(50);
    root->left= new node(30);
    root->left->left=new node(5);
    root->left->right=new node(20);
    root->right=new node(60);
    root->right->left=new node(45);
    root->right->right=new node(70); 
    root->right->right->left= new node(65);
    root->right->right->right = new node(80);

    largestBST(root);
    cout<<"max size :"<<maxSize<<endl;
    return 0;
}
