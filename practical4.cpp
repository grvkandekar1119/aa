#include <iostream>
#include <string>
using namespace std;

struct node
{
string data;
node *left;
node *right;
};

struct node *nnode, *temp, *root;
class Tree
{
node *root;
public:
           Tree()
           {
             root=NULL;
           }
 
           void create();
           void display(node *temp);
           void add();

};

void Tree :: create()
{
nnode = new node;
nnode->left=NULL;
nnode->right=NULL;
cout<<"\nEnter data : ";
cin>>nnode->data;

if(root == NULL)
{
   root=nnode;
}
}

void Tree :: add()
{
nnode =new node;
nnode->left=NULL;
nnode->right=NULL;
cout<<"\nEnter data : ";
cin>>nnode->data;

if(root->left == NULL)
{
  root->left=nnode;
  //cout<<root->left->data<<endl;
}

else
{
  root->right=nnode;
}

}

void Tree :: display(node *temp)
{
temp=root;
if(temp!=NULL)
{
display(temp->left);
cout<<temp->data<<endl;
//display(temp->left);
display(temp->right);
}
}


int main()
{
Tree t1;
t1.create();
t1.add();
t1.display(root);

}










