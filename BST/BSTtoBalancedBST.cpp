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
// node* buildBST(int *arr,int st,int end){
//     if(st>end){
//         return NULL;
//     }
//     int mid=st+(end-st)/2;
//     node* curr= new node(nodes[mid]);
//     curr->left= buildBST(nodes,st,mid-1);
//     curr->right=buildBST(nodes,mid+1,end);
//     return curr;
// }
void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
node* buildBSTvec(vector<int> arr,int st,int end){
    if(st>end){
        return NULL;
    }
    int mid=st+(end-st)/2;
    node* curr= new node(arr[mid]);
    curr->left= buildBSTvec(arr,st,mid-1);
    curr->right=buildBSTvec(arr,mid+1,end);
    return curr;
}
void getinorder(node* root,vector<int> &nodes){
    if(root==NULL){
        return;
    }
    getinorder(root->left,nodes);
    nodes.push_back(root->data);
    getinorder(root->right,nodes);
}
node* balancedBST(node* root){
    vector<int> nodes;
    getinorder(root,nodes);
    return buildBSTvec(nodes,0,nodes.size()-1);

}
int main(){
    node* root = new node(6);
    root->left= new node(5);
    root->left->left=new node(4);
    root->left->left->left=new node(3);
    root->right=new node(7);
    root->right->right=new node(8);
    root->right->right->right=new node(9); 
    root=balancedBST(root);
    preorder(root);
    cout<<endl;

    return 0;
}
