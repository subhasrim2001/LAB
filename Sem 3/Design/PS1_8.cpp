#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int);
};
Node::Node(int d)
{
    left = NULL;
    right = NULL;
    data = d;
}
void BST_Insert(Node* &root, Node* &x)
{
    if(root==NULL)
    {
        root = x;
        return;
    }
    else if(root->data < x->data)
    {
        BST_Insert(root->right, x);
    }
    else if(root->data > x->data)
    {
        BST_Insert(root->left, x);
    }
}
bool BST_search(Node* &root, int d)
{
    if(root==NULL)
    {
        return false;
    }
    else if(root->data == d)
    {
        return true;
    }
    else if(d < root->data)
    {
        return BST_search(root->left, d);
    }
    else if(d > root->data)
    {
        return BST_search(root->right, d);
    }
}
#include<iostream>
using namespace std;
int main()
{
    int n, i, val, m;
    Node *cur, *root = NULL;
    cout<<"\nEnter n:";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>val;
        cur = new Node(val);
        BST_Insert(root, cur);
    }
    cout<<"\nEnter m:";
    cin>>m;
    for(i=0; i<m; i++)
    {
        cin>>val;
        if(BST_search(root, val))
        {
            cout<<"\nYES";
        }
        else
        {
            cout<<"\nNO";
            cur = new Node(val);
            BST_Insert(root, cur);
        }
    }
    return 0;
}