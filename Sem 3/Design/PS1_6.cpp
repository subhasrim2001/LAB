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
int BST_Height(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        return 1;
    }
    else
    {
        int lheight = BST_Height(root->left);
        int rheight = BST_Height(root->right);
        if(rheight > lheight)
        {
            return rheight + 1;
        }
        else
        {
            return lheight + 1; 
        }
    }
}

int main()
{
    int n, i, val;
    Node *cur, *root = NULL;
    cout<<"\nEnter n:";
    cin>>n;
    cout<<"\nEnter the numbers:";
    for(i=0; i<n; i++)
    {
        cin>>val;
        cur = new Node(val);
        BST_Insert(root, cur);
    }
    cout<<"\nHeight of tree:"<<BST_Height(root);
    return 0;
}