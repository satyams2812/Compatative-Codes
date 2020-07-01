#include<bits/stdc++.h>
using namespace std;


struct node {
  public:
  int data;
  node *left;
  node *right;
   
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

void PreOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}

no_of_leaf(node *root)
{
     if(root==NULL)
     {
         return 0;
     }

   if(root->left==NULL && root->right==NULL)
   {
        return 1;
   }
   else
   {
       return no_of_leaf(root->left)+no_of_leaf(root->right);
   }
   
}

int main()
{
     node *root = buildTree();
     PreOrder(root);
     cout<<"\n";
    cout<<no_of_leaf(root);
}