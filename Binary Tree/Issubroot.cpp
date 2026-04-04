#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
static int idx = -1;
node *buildTree(vector<int> nodes)
{
    idx++;
    if (nodes[idx] == -1)
    {
        return NULL;
    }
    node *currnode = new node(nodes[idx]);
    currnode->left = buildTree(nodes);  // left subtree
    currnode->right = buildTree(nodes); // right subtree

    return currnode;
}
// void levelOrder(node *root)
// {
//     if (root == NULL)
//     {
//         return;
//     }
//     queue<node *> Q;
//     Q.push(root);
//     Q.push(NULL);
//     while (!Q.empty())
//     {
//         node *curr = Q.front();
//         Q.pop();
//         if (curr == NULL)
//         {
//             cout << endl;
//             if (Q.empty())
//             {
//                 break;
//             }
//             Q.push(NULL);
//         }
//         else
//         {
//             cout << curr->data << " ";

//             if (curr->left != NULL)
//             {
//                 Q.push(curr->left);
//             }
//             if (curr->right != NULL)
//             {
//                 Q.push(curr->right);
//             }
//         }
//     }
// }
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);

    int currht=max(leftht,rightht)+1;
    return currht;
}
int diam(node* root){
    if(root==NULL){
        return 0;
    }
    int currDiam=height(root->left)+height(root->right)+1;
    int leftDiam=diam(root->left);
    int rightDiam=diam(root->right);

    return max(currDiam,max(leftDiam,rightDiam));
}
pair<int,int> diam2(node* root){

    if(root==NULL){
        return make_pair(0,0);
    }

    pair<int,int> leftinfo=diam2(root->left);
    pair<int,int> rightinfo=diam2(root->right);

    int currDiam= leftinfo.second+rightinfo.second+1;
    int finalDiam=max(currDiam,max(leftinfo.first,rightinfo.second));
    int finalHt=max(leftinfo.second,rightinfo.second)+1;

    return make_pair(finalDiam,finalHt);
}
bool isIdentical(node* root1,node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
     else if(root1==NULL || root2==NULL){
        return false;
    }

    if(root1->data != root2->data){
        return false;
    }
    return isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right);
}
bool isSubtree(node* root,node* subroot){
    if(root==NULL && subroot==NULL){
        return true;
    }
    else if(root==NULL || subroot==NULL){
        return false;
    }
    if(root->data == subroot->data){
        if( isIdentical(root,subroot)){
            return true;
        };
    }
    int isLeftSubtree=isSubtree(root->left,subroot);
    if(isLeftSubtree){
        return isSubtree(root->right,subroot);
    }
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = buildTree(nodes);
    // levelOrder(root);
    // cout<<"Diameter : " <<diam2(root).first<<endl;
    node* subroot= new node(2);
    subroot->left=new node(4);
    subroot->right=new node(5);

    cout<<isSubtree(root,subroot)<<endl;
    
}