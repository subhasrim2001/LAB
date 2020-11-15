#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
};
void BSTinsert(Node *&root, Node *&X)
{
    if(root==NULL)
    {
        root=X;
    }
    else if(root->data < X->data)
    {
        BSTinsert(root->right, X);
    }
    else
    {
        BSTinsert(root->left, X);
    }
}
void BSTinorder(Node *&root)
{
    if(root!=NULL)
    {
        BSTinorder(root->left);
        cout<<root->data;
        BSTinorder(root->right);
    }
}
void printArray(int path[], int pathLen)
{
    int i;
    for(i=0; i<pathLen; i++)
    {
        cout<<path[i]<<"->";
    }
    cout<<"END\n";
}
void printPathsRecur(Node *&cur, int path[], int pathLen)
{
    if(cur==NULL)
    {
        return;
    }
    path[pathLen]=cur->data;
    pathLen++;
    if(cur->left==NULL && cur->right==NULL)
    {
        printArray(path, pathLen);
    }
    else
    {
        printPathsRecur(cur->left, path, pathLen);
        printPathsRecur(cur->right, path, pathLen);
    }
}
void printPaths(Node *&root)
{
    int path[100];
    int pathLen=0;
    printPathsRecur(root, path, pathLen);
}
int main()
{
    Node *root=NULL;
    int ch;
    do
    {
        cout<<"\nMENU:\n1.Insert\n2.Display\n3.PrintPaths\n4.Exit\nEnter choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        Node *X=new Node;
                        cout<<"\nEnter data:";
                        cin>>X->data;
                        X->left=X->right=NULL;
                        BSTinsert(root, X);
                        break;
                    }
            case 2: {
                        BSTinorder(root);
                        break;
                    }
            case 3: {
                        printPaths(root);
                        break;
                    }
            case 4: {
                        break;
                    }
            default:{
                        cout<<"\nInvalid input\n";
                    }
        }
    }while(ch!=4);
    return 0;
}
