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
    bool hasPathSum(Node *&, int);
};
bool BST::hasPathSum(Node *&root, int sum)
{
    if(root==NULL)
    {
        return false;
    }
    else if((root->left==NULL) && (root->right==NULL))
    {
        if(((root->data)-sum)==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return ((hasPathSum(root->left, sum-(root->data)))||(hasPathSum(root->right, sum-(root->data))));

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
    int ch, n;
    BST B1;
    do
    {
        cout<<"\nMENU:\n1.Insert\n2.hasPathSum\n3.Exit\nEnter choice:";
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
                        cout<<"\nEnter sum:";
                        cin>>n;
                        if(B1.hasPathSum(B1.root, n))
                        {
                            cout<<"\nSum is possible";
                        }
                        else
                        {
                            cout<<"\nSum is not possible";
                        }
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
