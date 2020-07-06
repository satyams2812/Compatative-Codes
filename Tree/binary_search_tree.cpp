#include<bits/stdc++.h>
using namespace std;

class node{
     public:
     int data;
     node *left;
     node *right;
     node(int d)
     {
          data = d;
         
     }

};


node *FindMin(node *root)
{
    while(root->left!=NULL)
    root = root->left;
    return root;
}

node *insert(node *root, int value)
{
      if(root==NULL)
    {
        return new node(value);
    }
 if(value<=root->data)
 {
     root->left = insert(root->left,value);
 }
 else if(value>root->data)
 {      
     root->right  = insert(root->right,value);
 }
   return root;
}

void preorder(node *root)
{
     if(root==NULL)
     {
          return;
     }
     cout<<root->data<< " ";
     preorder(root->left);
     preorder(root->right);
}

void inorder(node *root) // Every Bst Tree in IN-ORDER is a sorted value
{
     if(root==NULL)
     {
          return;
     }
     inorder(root->left);
     cout<<root->data<<" ";
     inorder(root->right);
}


node *Delete(node* root,int value)
{
     if(root==NULL)
     {
          return NULL;
     }
     else if(value<root->data)
     {
         root->left = Delete(root->left,value);
     }
     else if(value>root->data) 
      {
         root->right = Delete(root->right,value);
     }
     else
     {
          // case 1 : When No Child
          if(root->left == NULL && root->right == NULL)
          {
              delete root;
              root==NULL;
              return root;
          }
          // case 2 : When 1 Child 
          else if(root->left == NULL)
          {
               node *temp = root;
               root = root->right;
               delete temp;
               return root;
          } 
          else if(root->right == NULL)
          {
              node *temp =root;
              root = root->left;
              delete temp;
          }

          else
          {
               // case 3 : When 2 Children
              node * temp = FindMin(root->right);
                root->data = temp->data;
                root->right = Delete(root->right,temp->data);
          }
          
     }
      
      return root;

}


int main()
{ 
    node *root = NULL;
    root = insert(root,10);
    insert(root,5);
    insert(root,7);
    insert(root,2);
    insert(root,4);
    insert(root,8);
   inorder(root);
   root = Delete(root,5);
   cout<<"\n";
   inorder(root);
}