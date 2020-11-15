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
Node* BST_leftChild(Node* &root)
{
    if(root!=NULL)
    {
        return root->left;    
    }
    else
    {
        return NULL;
    }
}
Node* BST_rightChild(Node* &root)
{
    if(root!=NULL)
    {
        return root->right;    
    }
    else
    {
        return NULL;
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
void BST_Preorder(Node* &root)
{
    if(root!=NULL)
    {
        cout<<root->data<<" ";
        BST_Preorder(root->left);
        BST_Preorder(root->right);
    }
}
void BST_Postorder(Node* &root)
{
    if(root!=NULL)
    {
        BST_Postorder(root->left);
        BST_Postorder(root->right);
        cout<<root->data<<" ";
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
Node* BST_findMin(Node* &root)
{
    if(root==NULL || root->left==NULL)
    {
        return root;
    }
    else
    {
        return BST_findMin(root->left);
    }
}
int main()
{
    Node *root = NULL;
    int ch, d;
    do
    {
        cout<<"\nBST MENU:\n1.Insert\n2.Delete min node\n3.Find an element\n4.Find max\n"
        <<"5.Left child\n6.Right child\n7.Inorder\n8.Preorder\n9.Postorder\n10.Exit\nChoose(1-10):";
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
                        Node *cur = BST_findMin(root);
                        if(cur==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        else
                        {
                            BST_Deletion(root, cur->data);    
                        }
                        break;
                    }
            case 3: {
                        cout<<"\nEnter data:";
                        cin>>d;
                        if(BST_search(root, d))
                        {
                            cout<<"\nElement found\n";
                        }
                        else
                        {
                            cout<<"\nElement not found";
                        }
                        break;
                    }
            case 4: {
                        Node *cur = BST_findMax(root);
                        if(cur==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        else
                        {
                            cout<<"\nMax = "<<cur->data<<"\n";    
                        }
                        break;
                    }
            case 5: {
                        Node *cur = BST_leftChild(root);
                        if(cur==NULL)
                        {
                            cout<<"\nNo left child\n";   
                        }
                        else
                        {
                            cout<<"\nLeft child = "<<cur->data<<"\n";    
                        }
                        break;
                    }
            case 6: {
                        Node *cur = BST_rightChild(root);
                        if(cur==NULL)
                        {
                            cout<<"\nNo right child\n";
                        }
                        else
                        {
                            cout<<"\nRight child = "<<cur->data<<"\n";    
                        }
                        break;
                    }
            case 7: {
                        if(root==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        BST_Inorder(root);
                        break;
                    }
            case 8: {
                        if(root==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        BST_Preorder(root);
                        break;
                    }
            case 9: {
                        if(root==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        BST_Postorder(root);
                        break;
                    }
            case 10:{
                        break;
                    }
            default:{
                        cout<<"\nInvalid input, Choose again\n";
                        break;    
                    }
        }
    }while(ch!=10);
    return 0;
}
