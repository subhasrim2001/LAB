#include<bits/stdc++.h>
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
void findKeys(Node* &root, int a, int b, vector<int> &k)
{
    if(root!=NULL)
    {
        findKeys(root->left, a, b, k);
        if(root->data >= a && root->data <=b)
        {
            k.push_back(root->data);
        }
        findKeys(root->right, a, b, k);
    }
}
int minNodeData(Node* &root)
{
    if(root->left!=NULL)
    {
        return minNodeData(root->left);
    }
    else
    {
        return root->data;
    }
}
int countLeaves(Node* &root)
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
        return countLeaves(root->left) + countLeaves(root->right);
    }
}
int leftChildOnly(Node* &root)
{
    if(root!=NULL)
    {
        if(root->left!=NULL && root->right==NULL)
        {
            return root->data;
        }
        int a = leftChildOnly(root->left);
        int b = leftChildOnly(root->right);
        if(a!=-1)
        {
            return a;
        }
        else
        {
            return b;
        }
    }
    if(root == NULL)
    {
        return -1;
    }
}
bool AVL_search(Node* &root, int d)
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
        return AVL_search(root->left, d);
    }
    else if(d > root->data)
    {
        return AVL_search(root->right, d);
    }
}
void AVLDelete(Node* &root, int d)
{
    if(root==NULL)
    {
        return;
    }
    else if(d < root->data)
    {
        AVLDelete(root->left, d);
    }
    else if(d > root->data)
    {
        AVLDelete(root->right, d);
    }
    else
    {
        //key found
        if(root->left!=NULL && root->right!=NULL)
        {
            int d = minNodeData(root->right);
            root->data = d;
            AVLDelete(root->right, d);
        }
        else
        {
            Node* temp;
            temp = root;
            root = root->left!=NULL ? root->left : root->right;
            delete temp;
        }
    }
    //deletion complete
    if(root == NULL)
    {
        return;
    }
    //change balance
    root->height = 1 + getMax(getHeight(root->left), getHeight(root->right));
    int b = getBalance(root);
    //R0, 1
    if(b > 1 && getBalance(root->left)>=0)
    {
        root = LL_Rotation(root);
    }
    //R-1
    else if(b > 1 && getBalance(root->left)<0)
    {
        root->left = RR_Rotation(root->left);
        root = LL_Rotation(root);
    }
    //L0, -1
    else if(b < -1 && getBalance(root->right)<=0)
    {
        root = RR_Rotation(root);
    }//L1
    else if(b < -1 && getBalance(root->right)>0)
    {
        root->right = LL_Rotation(root->right);
        root = RR_Rotation(root);
    }
}
int main()
{
    Node *root = NULL;
    Node *cur;
    int ch, a, d;
    do
    {
        cout<<"\n1.INSERT\n2.DISPLAY\n3.FIND AN ELEMENT\n4.FIND HEIGHT\n5.INORDER TRAVERSAL\n6.DELETE ROOT NODE\n7.DELETE NODE WITH ONLY LEFT CHILD\n8.DELETE MIN VALUE NODE\n9.COUNT NUMBER OF LEAVES\n10.FIND NODES BETWEEN a AND b\n11.EXIT\nEnter choice:";
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
                        cout<<"\nEnter data:";
                        cin>>d;
                        if(AVL_search(root, d))
                        {
                            cout<<"\nElement found\n";
                        }
                        else
                        {
                            cout<<"\nElement not found\n";
                        }
                        break;
                    }
            case 4: {
                        cout<<"\nThe height of the AVL tree is:"<<getHeight(root)<<"\n";
                        break;
                    }
            case 5: {
                        if(root==NULL)
                        {
                            cout<<"\nEmpty tree\n";
                        }
                        Inorder(root);
                        break;    
                    }
            case 6: {
                        if(root==NULL)
                        {
                            cout<<"\nRoot node does not exist\n";
                        }
                        else
                        {
                            AVLDelete(root, root->data);
                            cout<<"\nRoot node deleted\n";
                        }
                        break;
                    }
            case 7: {
                        d = leftChildOnly(root);
                        if(d == -1)
                        {
                            cout<<"\nNo nodes exists\n";
                            break;
                        }
                        AVLDelete(root, d);
                        cout<<"\nA node with only left child has been deleted\n";
                        break;
                    }
            case 8: {
                        d = minNodeData(root);
                        AVLDelete(root, d);
                        cout<<"\nThe node with minimum value in the tree has been deleted\n";
                        break;
                    }
            case 9: {
                        cout<<"\nThe number of leaves nodes is:"<<countLeaves(root)<<"\n";
                        break;
                    }
            case 10:{
                        cout<<"\nEnter a:";
                        cin>>a;
                        cout<<"\nEnter b:";
                        cin>>d;
                        vector<int> k;
                        findKeys(root, a, d, k);
                        if(k.size() == 0)
                        {
                            cout<<"\nNo elements\n";
                            break;
                        }
                        cout<<"\nThe list of keys between "<<a<<" and "<<d<<" is:"<<"\n";
                        for(auto it=k.begin(); it!=k.end(); it++)
                        {
                            cout<<*it<<" ";
                        }
                        break;
                    }
            case 11:{
                        break;
                    }
            default:{
                        cout<<"\nInvalid Input\n";
                    }
        }
    }while(ch!=11);
    return 0;
}
