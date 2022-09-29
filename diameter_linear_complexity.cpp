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

pair <int,int > diameter(node* root)
{
    if(root==NULL)
    {
        pair <int ,int> p=make_pair(0,0);
        return p;
    }
  pair <int ,int> left=diameter(root->left);
  pair <int ,int> right=diameter(root->right);
  int op1=left.first;
  int op2=right.first;
  int op3=left.second+right.second+1; 
pair<int,int>ans;
ans.first=max(op3,max(op1,op2));
ans.second=max(left.second,right.second)+1;
return ans;
}
int main()
{
    node* root=NULL;
    create_bt(root);
    cout<<diameter(root).first;
} 