#include<bits/stdc++.h>
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
void BST_Convert(Node* &root1, Node* &root2)
{
    //lets do preorder
    if(root1!=NULL && root2!=NULL)
    {
        while(root1->data != root2->data)
        {
            if(root1->data > root2->data) //if root is bigger we need to rotate to the right = LL or LR
            {
                if(root1->left!=NULL && root1->left->right!=NULL && root1->left->right->data == root2->data) //LR
                {
                    cout<<"\nLR Rotation on "<<root1->data;
                    root1->left = RR_Rotation(root1->left);
                    root1 = LL_Rotation(root1);
                }
                else if(root1->left!=NULL) //LL
                {
                    cout<<"\nLL Rotation on "<<root1->data<<"\n";
                    root1 = LL_Rotation(root1);
                }
            }
            else if(root1->data < root2->data)//we need to rotate to the left = RR or RL
            {
                if(root1->right!=NULL && root1->right->left!=NULL && root1->right->left->data == root2->data)//RL
                {
                    cout<<"\nRL Rotation on "<<root1->data;
                    root1->right = LL_Rotation(root1->right);
                    root1 = RR_Rotation(root1);
                }
                else if(root1->right!=NULL)//RR
                {
                    cout<<"\nRR Rotation on "<<root1->data;
                    root1 = RR_Rotation(root1);
                }
            }
        }
    BST_Convert(root1->left, root2->left);
    BST_Convert(root2->right, root2->right);
    }
}
int main()
{
    //convert root1 to root2
    Node *root1 = NULL, *root2 = NULL;
    int d;
    cout<<"\nEnter elements of tree 1 in the order in which you want to be inserted(-1 to stop):";
    do
    {
        cin>>d;
        if(d == -1)
        {
            break;
        }
        Node *t = new Node(d);
        BST_Insert(root1, t);
    }while(1);
    cout<<"\nEnter elements of tree 2 in the order in which you want to be inserted(-1 to stop):";
    do
    {
        cin>>d;
        if(d == -1)
        {
            break;
        }
        Node *t = new Node(d);
        BST_Insert(root2, t);
    }while(1);
    BST_Convert(root1, root2);
}