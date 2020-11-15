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
void BST_Inorder(Node* &root)
{
    if(root!=NULL)
    {
        BST_Inorder(root->left);
        cout<<root->data<<" ";
        BST_Inorder(root->right);
    }
}
Node* BST_findMax(Node* &root)
{
    if(root==NULL || root->right==NULL)
    {
        return root;
    }
    else
    {
        return BST_findMax(root->right);
    }
}
bool BST_Deletion(Node* &root, int d)
{
    if(root == NULL)
    {
        return false;
    }
    else if(root->data > d)
    {
        BST_Deletion(root->left, d);
    }
    else if(root->data < d)
    {
        BST_Deletion(root->right, d);
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        root->data = (BST_findMax(root->left))->data;
        BST_Deletion(root->left, root->data);
    }
    else
    {
        Node* temp;
        temp = root;
        root = root->left!=NULL ? root->left : root->right;
        delete temp;
    }
}
int BST_LeafNodes(Node* &root)
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
        return BST_LeafNodes(root->left) + BST_LeafNodes(root->right);
    }
}
int main()
{
    Node *root = NULL;
    int ch, d;
    do
    {
        cout<<"\nBST MENU:\n1.Insert\n2.Delete\n3.Leaf Nodes\n4.Exit\nChoose(1-4):";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter data:";
                        cin>>d;
                        Node *cur = new Node(d);
                        BST_Insert(root, cur);
                        break;
                    }
            case 2: {
                        cout<<"\nEnter data:";
                        cin>>d;
                        BST_Deletion(root, d);    
                        break;
                    }
            case 3: {
                        cout<<"\nNo of leaf nodes:"<<BST_LeafNodes(root)<<"\n";
                        break;
                    }
            case 4:{
                        break;
                    }
            default:{
                        cout<<"\nInvalid input, Choose again\n";
                        break;    
                    }
        }
    }while(ch!=4);
    return 0;
}
