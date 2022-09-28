#include<iostream>
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
    cout<<"enter data";
    int x;
    cin>>x;
    if(x==-1)
    {
        return ;
    }
    root=new node(x);
    cout<<"enter details of left node of "<<root->data;
    create_bt(root->left);
    cout<<"enter details of right node of "<<root->data;
    create_bt(root->right);
}

int height_bt(node*root)
{
  if(root==NULL)
  {
    return 0;
  }
int left=height_bt(root->left);
int right=height_bt(root->right);
return (max(left,right)+1);
}
int dia(node *root)
{
   if(root==NULL)
   {
     return 0;
   }
   int d1=dia(root->left);
   int d2=dia(root->right);
   int h1=height_bt(root->left)+1+height_bt(root->right);
   return max(max(d1,d2),h1);
}

int main()
{
    node* root=NULL;
    create_bt(root);
    cout<<"height of bt"<<height_bt(root);
   cout<<"diameter of binary tree  "<< dia(root)<<endl;
}   