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
int BST_search(Node* &root, int d)
{
    if(root==NULL)
    {
        return -1;
    }
    else if(root->data == d)
    {
        return 0;
    }
    else if(d < root->data)
    {
        return 1 + BST_search(root->left, d);
    }
    else if(d > root->data)
    {
        return 1+ BST_search(root->right, d);
    }
}
int main()
{
    Node *root = NULL, *cur;
    int i;
    for(i=0; i<=10; i++)
    {
        cur = new Node(i);
        BST_Insert(root, cur);
    }
    cout<<"\nNo of searches: "<<BST_search(root, 10)<<"\n";
    return 0;
}
