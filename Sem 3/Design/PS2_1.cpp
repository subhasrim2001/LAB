#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    int height;
    Node *left;
    Node *right;
    Node(int );
};
void Inorder(Node* &);
Node::Node(int d)
{
    left = NULL;
    right = NULL;
    data = d;
    height = 1;
}
int getMax(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
int getHeight(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}
int getBalance(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return getHeight(root->left) - getHeight(root->right);
    }
}
Node* LL_Rotation(Node* root)
{
    Node* K = root->left;
    root->left = K->right;
    K->right = root;
    return K;
}
Node* RR_Rotation(Node* root)
{
    Node *K = root->right;
    root->right = K->left;
    K->left = root;
    return K;
}
void AVLInsert(Node* &root, Node* &cur)
{
    //insert element
    if(root == NULL)
    {
        root = cur;
        return;
    }
    else if(cur->data < root->data)
    {
        AVLInsert(root->left, cur);
    }
    else if(cur->data > root->data)
    {
        AVLInsert(root->right, cur);
    }
    else
    {
        //equal 
        return;
    }
    
    //update height of the previous node
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    
    //get balance
    int balance = getBalance(root);
    //if unbalanced
    //LL rotation
    if(balance > 1 && cur->data < root->left->data)
    {
        root = LL_Rotation(root);
        cout<<"\nDisplaying after LL rotation on "<<root->data<<"\n";
        Inorder(root);
        cout<<"\n";
    }//LR Rotation
    else if(balance > 1 && cur->data >  root->left->data)
    {
        root->left = RR_Rotation(root->left);
        root = LL_Rotation(root);
        cout<<"\nDisplaying after LR rotation on "<<root->data<<"\n";
        Inorder(root);
        cout<<"\n";
        
    }//RR Rotation
    else if(balance < -1 && cur->data > root->right->data)
    {
        root = RR_Rotation(root);
        cout<<"\nDisplaying after RR rotation on "<<root->data<<"\n";
        Inorder(root);
        cout<<"\n";
    }//RL Rotation
    else if(balance < -1 && cur->data < root->right->data)
    {
        root->right = LL_Rotation(root->right);
        root = RR_Rotation(root);
        cout<<"\nDisplaying after RL rotation on "<<root->data<<"\n";
        Inorder(root);
        cout<<"\n";
    }
}
void Inorder(Node* &root)
{
    if(root!=NULL)
    {
        Inorder(root->left);
        cout<<root->data<<" ";
        Inorder(root->right);
    }
}
void AVL_printLevel(Node* &root, int i)
{
    if(root==NULL)
    {
        return;
    }
    else if(i==1)
    {
        cout<<root->data<<" ";
    }
    else
    {
        AVL_printLevel(root->left, i-1);
        AVL_printLevel(root->right, i-1);
    }
    
}
int AVL_height(Node* &root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        int lheight = AVL_height(root->left);
        int rheight = AVL_height(root->right);
        if(rheight > lheight)
        {
            return 1+rheight;   
        }
        else
        {
            return 1+lheight;
        }
    }
}
void AVL_levelOrderTraversal(Node* &root)
{
    int i;
    for(i=1; i<=AVL_height(root); i++)
    {
        AVL_printLevel(root, i);
    }
}
int main()
{
    Node *root = NULL;
    Node *cur;
    int ch, d;
    do
    {
        cout<<"\n1.INSERT\n2.DISPLAY\n3.EXIT\nInsert choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: {
                        cout<<"\nEnter data:";
                        cin>>d;
                        cur = new Node(d);
                        AVLInsert(root, cur);
                        break;
                    }
            case 2: {
                        Inorder(root);
                        break;
                    }
            case 3: {
                        break;
                    }
            default:{
                        cout<<"\nInvalid Input\n";
                    }
        }
    }while(ch!=3);
    return 0;
}
