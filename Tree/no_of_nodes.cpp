#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
  node *right;
  node *left;
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
    if(d == -1)
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
    cout<<root->data<< " ";
    PreOrder(root->left);
    PreOrder(root->right);
}


countNoofNodes(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1+countNoofNodes(root->left)+countNoofNodes(root->right);
} 


int main()
{
    node *root = buildTree();
    PreOrder(root);
   cout<<"\n";
  cout<< countNoofNodes(root);
}