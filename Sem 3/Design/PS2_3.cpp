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
void BST_Inorder_Elements(Node* &root, vector<int> &v)
{
    if(root!=NULL)
    {
        BST_Inorder_Elements(root->left, v);
        v.push_back(root->data);
        BST_Inorder_Elements(root->right, v);
    }
}
void BalancedTree(vector<int>v, Node* &root, int l, int h)
{
    if(l <= h)
    {
        int mid = (l + h)/2;
        Node* t = new Node(v[mid]);
        root = t;
        BalancedTree(v, root->left, l, mid-1);
        BalancedTree(v, root->right, mid+1, h);
    }
}
void Merge(vector<int> v1, vector<int> v2, vector<int> &v3)
{
    auto i = v1.begin();
    auto j = v2.begin();
    while(i!=v1.end() && j<v2.end())
    {
        if(*i < *j)
        {
            v3.push_back(*i);
            i++;
        }
        else if(*i == *j)
        {
            v3.push_back(*i);
            i++;
            j++;
        }
        else
        {
            v3.push_back(*j);
            j++;
        }
    }
    if(i==v1.end())
    {
        while(j!=v2.end())
        {
            v3.push_back(*j);
            j++;
        }
    }
    else
    {
        while(i!=v1.end())
        {
            v3.push_back(*i);
            i++;
        }
    }
}
int main()
{
    Node *root1 = NULL, *root2 = NULL, *root3 = NULL;
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
    vector<int> v1, v2, v3;
    BST_Inorder_Elements(root1, v1);
    BST_Inorder_Elements(root2, v2);
    Merge(v1, v2, v3);
    BalancedTree(v3, root3, 0, v3.size()-1);
    BST_Inorder(root3);
    return 0;
}