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
void levelOrder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> Q;
    Q.push(root);
    while (!Q.empty())
    {
        node *curr = Q.front();
        Q.pop();
        cout << curr->data << " ";

        if (curr->left != NULL)
        {
            Q.push(curr->left);
        }
        if (curr->right != NULL)
        {
            Q.push(curr->right);
        }
    }
}
void kthhelper(node *root, int k, int currLevel)
{
    if (root == NULL)
    {
        return;
    }
    if (currLevel == k)
    {
        cout << root->data << " ";
        return;
    }
    kthhelper(root->left, k, currLevel + 1);
    kthhelper(root->right, k, currLevel + 1);
}
void Kthlevel(node *root, int k)
{
    kthhelper(root, k, 1);
    cout << endl;
}
bool rootToNode(node *root, int n, vector<int> &path)
{
    if (root == NULL)
    {
        return false;
    }
    path.push_back(root->data);
    if(root->data==n){
        return true;
    }
    int isleft = rootToNode(root->left, n, path);
    int isright = rootToNode(root->right, n, path);

    if (isleft || isright)
    {
        return true;
    }
    path.pop_back();
    return false;
}
int LCA(node *root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    rootToNode(root, n1, path1);
    rootToNode(root, n2, path2);
    int lca = -1;
    for (int i = 0, j = 0; i < path1.size() && i < path2.size(); i++, j++)
    {
        if (path1[i] != path2[i])
        {
            return lca;
        }
        lca = path1[i];
    }
    return lca;
}
node* LCA2(node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data == n1 || root->data==n2){
        return root;
    }
    node* leftLCA= LCA2(root->left,n1,n2);
    node* rightLCA=LCA2(root->right,n1,n2);
    if(leftLCA !=NULL && rightLCA !=NULL){
        return root;
    }
    return leftLCA ==NULL ? rightLCA:leftLCA;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = buildTree(nodes);

    // Kthlevel(root,2);
    int n1 = 4, n2 = 5;
    cout << "LCA =" << LCA2(root, n1, n2)->data;
    return 0;
}