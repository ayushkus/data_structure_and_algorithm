//binary tree creation and traversal in C++
#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node *left;
    node *right;
     node(int data)
{
      this->data=data;
      this->left=NULL;
      this->right=NULL;
}
};

node* create_bt(node* root)
{
 cout<<"enter data";
 int x;
 cin>>x;
 root=new node(x);
 if(x==-1)
{
  return NULL;
}

cout<<"enter data to insert at the left "<<x<<endl;
root->left=create_bt(root->left);
cout<<"enter the data to insert at thr right "<<x<< endl;
root->right=create_bt(root->right);
return root;
}

void lever_order_traver(node* root)
{
    queue <node*> q;
    q.push(root);
    q.push(NULL);
     while(!q.empty())
     {
       node* temp=q.front();
       q.pop();
       if(temp==NULL)
       {cout<<endl;
        if(!q.empty())
        {
            q.push(NULL);
        }
       }
       else{
        cout<<temp->data<<" ";
        if(temp->left)
           q.push(temp->left);
        if(temp->right)
        {
            q.push(temp->right);
        }
       }
    
     }
}
void preorder(node* root)
{
    if(root==NULL)
    {
    return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node* root)
{
    if(root==NULL)
    {
    return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node* root)
{
    if(root==NULL)
    {
    return ;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
void build_from_levelorder_traversal(node* &root)
{
    queue<node*> qu1;
    int data;
    cout<<"enter the data of root node";
    cin>>data;
    root=new node(data);
    qu1.push(root);
    while(!qu1.empty())
    {
        node* temp=qu1.front();
        qu1.pop();
        cout<<"enter the data for left of"<<temp->data<<endl;
        int templeft;
        cin>>templeft;
        if(templeft!=-1)
        {
        temp->left=new node(templeft);
        qu1.push(temp->left);
        }
        
        cout<<"enter the data for right of"<<temp->data<<endl;
        int tempright;
        cin>>tempright;
        if(tempright!=-1)
        {
        temp->right=new node(tempright);
        qu1.push(temp->right);
        }
    }


}

int main()
{
     node *root=NULL;
     build_from_levelorder_traversal(root);
     lever_order_traver(root);
    // root=create_bt(root);
    // lever_order_traver(root);
    // cout<<endl<<endl;
    // cout<<"preorder";
    // preorder(root);
    // cout<<endl<<endl;
    // cout<<"postorder";
    // postorder(root);
    // cout<<endl<<endl;
    // cout<<"inorder";
    // postorder(root);


    return 0;
}


