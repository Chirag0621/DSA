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
    Q.push(NULL);
    while (!Q.empty())
    {
        node *curr = Q.front();
        Q.pop();
        if (curr == NULL)
        {
            cout << endl;
            if (Q.empty())
            {
                break;
            }
            Q.push(NULL);
        }
        else
        {
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
}
int height(node* root){
    if(root==NULL){
        return 0;
    }
    int leftht=height(root->left);
    int rightht=height(root->right);

    int currht=max(leftht,rightht)+1;
    return currht;
}
int main()
{
    vector<int> nodes = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
    node *root = buildTree(nodes);
    // levelOrder(root);
    cout<<height(root);
    return 0;
}