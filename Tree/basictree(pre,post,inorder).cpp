#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
     node *left;
    node *right;
    int data;
   
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
       
};


node *buildTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node *root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void preOrder(node *root)
{
     if(root==NULL)
     {
         return;
     }
     
     cout<< root->data<<" ";
     preOrder(root->left);
     preOrder(root->right);
}

void postOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<< root->data << " ";
}

void inOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<< " ";
    inOrder(root->right);
}

int main()
{
    node *root = buildTree();
    preOrder(root);
    cout<<"\n";
    postOrder(root);
    cout<<"\n";
    inOrder(root);
}
