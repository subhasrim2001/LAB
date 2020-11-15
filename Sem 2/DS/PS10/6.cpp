#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
class BST
{
public:
    Node *root;
    BST();
    void BSTinsert(Node *&, Node *&);
    void doubleTree(Node *&);
    void BSTinorder(Node *&);
};
void BST::BSTinorder(Node *&root)
{
    if(root!=NULL)
    {
        BSTinorder(root->left);
        cout<<root->data;
        BSTinorder(root->right);
    }
}
void BST::doubleTree(Node *&root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        Node *cur=new Node;
        cur->data=root->data;
        cur->left=root->left;
        cur->right=NULL;
        doubleTree(root->left);
        root->left=cur;
        doubleTree(root->right);
    }
}
void BST::BSTinsert(Node *&root, Node *&X)
{
    if(root==NULL)
    {
        root=X;
    }
    else if(root->data > X->data)
    {
        BSTinsert(root->left, X);
    }
    else
    {
        BSTinsert(root->right, X);
    }
}
BST::BST()
{
    root=NULL;
}
int main()
{
    int ch;
    BST B1;
    do
    {
        cout<<"\nMENU:\n1.Insert\n2.doubleTree\n3.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        Node *cur=new Node;
                        cout<<"\nEnter data:";
                        cin>>cur->data;
                        cur->left=cur->right=NULL;
                        B1.BSTinsert(B1.root, cur);
                        break;
                    }
            case 2: {
                        B1.doubleTree(B1.root);
                        B1.BSTinorder(B1.root);
                        break;
                    }
            case 3: {
                        break;
                    }
            default:{
                        cout<<"\nInvalid input\n";
                    }
        }
    }while(ch!=3);
    return 0;
}
