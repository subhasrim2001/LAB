#include<iostream>
#include<limits.h>
using namespace std;
class Node
{
    public:
       int data;
       Node *left;
       Node *right;
       Node(int);
};
Node::Node(int data)
{
    this->data=data;
    this->left=this->right=NULL;
}
class BST
{
    public:
    Node *root;
    BST();
    bool isBST(Node *&, int =INT_MIN, int =INT_MAX);
};
bool BST::isBST(Node *&root, int min, int max)
{
    if(root==NULL)
    {
        return true;
    }
    else if(root->data < min || root->data > max)
    {
        return false;
    }
    else
    {
        return isBST(root->left, min, root->data-1) && isBST(root->right, root->data + 1, max);
    }
}
BST::BST()
{
    root=NULL;
}
int main()
{
    BST B1;
    B1.root = new Node(4);
    (B1.root)->left=new Node(8);
    (B1.root)->right=new Node(5);
    (B1.root)->left->left=new Node(1);
    (B1.root)->left->right=new Node(3);
    if(B1.isBST(B1.root))
    {
        cout<<"\nIs BST";
    }
    else
    {
        cout<<"\nNot a BST";
    }
    return 0;
}
