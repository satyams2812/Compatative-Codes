#include<bits/stdc++.h>
using namespace std;

struct node{
    public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data =d;
        left=right=NULL;
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

void levelOrder(node *root)
{
      if(root==NULL)
      {
           return;
      }

   queue<node *> Q;
   Q.push(root);
   while(!Q.empty())
   {
       node *current = Q.front();
       cout<<current->data<<" ";
       if(current->left !=NULL )
       {
           Q.push(current->left);
       }
       if(current->right !=NULL )
       {
           Q.push(current->right);
       }
     Q.pop();       
   }

}

int main()
{
    node *root = buildTree();
    PreOrder(root);
    cout<<"\n";
    levelOrder(root);


}