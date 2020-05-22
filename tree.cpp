#include<bits/stdc++.h>
using namespace std;

class node
{
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
    cin >> d;
    if (d == -1)
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
    if (root == NULL)
        return;
    cout << root->data << ", ";
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
   
     cout<<root->data<<" , ";
}

void inOrder(node *root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" , ";
    inOrder(root->right);
}

int countNoofNodes(node *root)
{
    if(root==NULL)
    {
        return 0 ;
    }
    return 1+countNoofNodes(root->left)+ countNoofNodes(root->right);
}
 
int height(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}


/* int replaceNodewithSum(node *root)
{
        if(root == NULL)
        { return 0;}
        int left_sum = replaceNodewithSum(root->left);
        int right_sum = replaceNodewithSum(root->right);
        root->data = left_sum+ right_sum;
        return root->data;

} */

void levelOrderTransversal(node* root)
{
     if(root==NULL)
     {
        return;
     }
     queue<node*> q;
     q.push(root);
     while(!q.empty())
     {
            node* front  = q.front();
            cout<<front->data<<" ,";
           q.pop();
           if(front->left!=NULL)
           {
               q.push(front->left);
           }
           if(front->right!=NULL)
           {
               q.push(front->right);
           }
     }
}

void distinctLevel(node *root)
{
     queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* front = q.front();
        q.pop();
        if(front != NULL){
            cout << front->data<<" ";
            while(front != NULL){
                if(front->left) 
                q.push(front->left);
                if(front->right)
                q.push(front->right);
                front = q.front();
                q.pop();
            }
            cout <<endl;
            q.push(NULL); // present level is completed traversed
        }

    }
}

void leftView(node *root,int level, int &maxLevel)
{
    if(root==NULL)
    return;
    if(level>maxLevel)
    {
        cout<<root->data<< " , ";
        maxLevel = level;
    }
    leftView(root->left, level+1, maxLevel);
    leftView(root->right, level+1 , maxLevel);
}

void rightView(node *root , int level , int &maxLevel)
{
    if(root == NULL)
    {
        return;
    }
    if(level>maxLevel)
    {
        cout<<root->data<< " ,";
        maxLevel  = level;
    }
    rightView(root->right, level+1 , maxLevel);
    rightView(root->left, level+1 , maxLevel);
}

void zigzag(node *root)
{
    stack<node*> currlevel , nextlevel;
    bool left_to_right = true;
    currlevel.push(root);
    while(!currlevel.empty() or !nextlevel.empty())
    {
        node *top = currlevel.top();
        cout<<top->data<< " , ";
        currlevel.pop();
        if(left_to_right==true)
        {
           if(top->left)
           nextlevel.push(top->left);
           if(top->right)
           nextlevel.push(top->right);
        }
        else{
            if(top->right)
            nextlevel.push(top->right);
            if(top->left)
            nextlevel.push(top->left);
        }

        if(currlevel.empty()==true)
        {
            left_to_right =! left_to_right;
            swap(currlevel,nextlevel);
            cout<< endl;
        }
    }
}

map<int,vector<int>>mp;
 void VerticalOrderTransversal(node *root, int level)
 {
     if(root==NULL)
     return;

     mp[level].push_back(root->data);
     VerticalOrderTransversal(root->left, level-1);
     VerticalOrderTransversal(root->right, level+1);
 }


int main()
{
    node *root = buildTree();
    preOrder(root);
    cout<<endl;
    int maxlevel = 0;
    inOrder(root);
     cout<<endl;
     postOrder(root);
          cout<<endl;
   cout<< countNoofNodes(root);
         cout<<endl;
      levelOrderTransversal(root);
        cout<<endl;
       distinctLevel(root);
 cout<<endl;
  cout<<"Height => "<< height(root);
 cout<<endl;
 leftView(root,1,maxlevel);
 cout<<endl;
 rightView(root,1,maxlevel);
cout<<endl;
zigzag(root);
cout<<endl;
VerticalOrderTransversal(root,0);
for(auto it:mp)
{
        for(int x: it.second)
        {
            cout<<x << " ";
        }
        cout<<endl;
}

//    cout<<replaceNodewithSum(root);
}