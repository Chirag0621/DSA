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
node* buildBST(int *arr,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    node* curr= new node(arr[mid]);
    curr->left= buildBST(arr,st,mid-1);
    curr->right=buildBST(arr,mid+1,end);
    return curr;
}
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    int arr[7]={3,4,5,6,7,8,9};
    node* root=buildBST(arr,0,6);
    preorder(root);
    cout<<endl;
    return 0;
}
