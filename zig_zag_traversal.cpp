#include<iostream>
#include<stack>
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
void zig_zag(node* root)
{
    if(root==NULL)
    {
        return;
    }
stack<node*> st1;
stack<node*> st2;
st1.push(root);
bool ltr=true;
while(!st1.empty())
{
node* temp=st1.top();
st1.pop();
if(temp)
{
cout<<temp->data<<" ";
if(ltr)
{   
    if(temp->left)
    st2.push(temp->left);
    if(temp->right)
    st2.push(temp->right);
}
else{
    if(temp->right)
    st2.push(temp->right);
    if(temp->left)
    st2.push(temp->left);
}
}
if(st1.empty())
{
    swap(st1,st2);
    ltr=!ltr;
}
}
}

int main()
{
    node* root=NULL;
    create_bt(root);
    zig_zag(root);
}   