#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left=right=NULL;
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
    root->left=buildTree();
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

int replaceNodewithSum(node *root)
{
      if(root==NULL)
      {
          return 0;
      }
      int left_max = replace_node_with_sum(root->left);
      int right_max = replace_node_with_sum(root->right);
       root->data = left_max+right_max;
       return root->data;
     
}

int main()
{

  node *root = buildTree();
  PreOrder(root);
  cout<<"\n";
 cout<< replaceNodewithSum(root);  

}