#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class node{
    public:
    node*left;
    int data;
    node* right;
    node(int data)
    {
        this->left=NULL;
        this->data=data;
        this->right=NULL;
    } 
};
void create_bt(node* &root)
{
cout<<"enter the data";
int x;
cin>>x;
if(x==-1)
{
    return;
}
root=new node(x);
cout<<"enter data for left tree"<<root->data<<endl;
create_bt(root->left);
cout<<"enter data for right tree"<<root->data<<endl;
create_bt(root->right);
}

// PRINT LEFT SIDE
void leftside(node*root,vector<int> &ans1)
{
 if(root==NULL)
 return ;
 if(root->left==NULL && root->right==NULL)
 return ;
 ans1.push_back(root->data); 
  if(root->left)
 {
    leftside(root->left,ans1);
 }
 else 
 leftside(root->right,ans1);
}
// PRINT BOTTOM SIDE 
void bottomside(node*root,vector<int> &ans1)
{   
  if(root==NULL)
  return ;
  if(root->left ==NULL && root->right==NULL)
  {
    ans1.push_back(root->data);
    return;
  } 
  bottomside(root->left,ans1);
  bottomside(root->right,ans1);

}
// // PRINT RIGHT SIDE IN REVERSE
void rightup(node*root,vector<int>&ans1)
{
  if((root==NULL)|| (root->right==NULL &&root->left==NULL))
  {
    return ;
  }
  if(root->right)
  {
    rightup(root->right,ans1);
  }
  else 
  rightup(root->left,ans1);
  ans1.push_back(root->data);
}
void boundary_traversal(node *root)
{  vector<int>ans1;
ans1.push_back(root->data);
    leftside(root->left,ans1);
    bottomside(root->left,ans1);
    bottomside(root->right,ans1);
    rightup(root->right,ans1);
    int x=ans1.size();
    for(int i=0;i<x;i++)
    {
        cout<<ans1[i];
    }
}

int main()
{
    node* root=NULL;
    create_bt(root);
    boundary_traversal(root);
    
}   