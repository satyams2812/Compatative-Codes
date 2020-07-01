#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
};

struct node* head = NULL;


node* atBeg(node *head, int b)
{
  node* new_node = new node();
   new_node->data = b;
   new_node->next = head;
   head = new_node;
}

void print(node *curr)
{
    while(curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr= curr->next;
    }
}

int main()
{
   head = atBeg(head,4);
   head = atBeg(head,5);
   head = atBeg(head,6);
   head = atBeg(head,7);
   print(head);
}