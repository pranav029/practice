#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* l_child;
    node* r_child;
    node(int data):data(data),l_child(nullptr),r_child(nullptr){};
    node* insert(node*,int);
    void inOrder(node*);
    node* flatten(node*);
    void display(node*);
    node* inOdpred(node*);
};
node* node::insert(node* root,int data)
{
    if(!root)return new node(data);
    if(data<root->data)
    root->l_child=insert(root->l_child,data);
    else
    root->r_child=insert(root->r_child,data);
    return root;
}
node* node::inOdpred(node* root)
{
    node* temp=root;
    while(temp->r_child)
      temp=temp->r_child;
   return temp;
}
node* node::flatten(node* root)
{
    if(!root)return nullptr;
     if(root->l_child)
     {
         node* temp=inOdpred(root->l_child);
         temp->r_child=root->r_child;
         root->r_child=root->l_child;
         root->l_child=nullptr;
     }
     root->r_child=flatten(root->r_child);
     return root;
}
void node::inOrder(node* root)
{
    if(!root)return;
    inOrder(root->l_child);
    cout<<root->data<<" ";
    inOrder(root->r_child);
}
void node::display(node* root)
{
    cout<<"\n";
    node* temp=root;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->r_child;
    }
}
int main(){
    node T(0),*root=nullptr;
    root=T.insert(root,100);
    root=T.insert(root,20);
    root=T.insert(root,10);
    root=T.insert(root,500);
    root=T.insert(root,30);
    T.inOrder(root);
    root=T.flatten(root);
    T.display(root);
}
// 10 20 30 100 500
// 100 20 10 30 500
//10 20 30 100 500
//100 20 10 30 500
