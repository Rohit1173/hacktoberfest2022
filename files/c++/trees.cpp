#include<bits/stdc++.h>
using namespace std;
class TreeNode {
public:
int value;
TreeNode *left;
TreeNode *right;
TreeNode(){
value=0;
left= NULL;
right= NULL;
}
TreeNode(int x)
{
value=x;
left= NULL;
right= NULL;
}
};
class BST{
public:
TreeNode* root;
BST()
{
root=NULL;
}
void insert(TreeNode* node)
{
if(root==NULL)
root = node;
else{
TreeNode *temp=root;
while(temp!=NULL)
{
if(node->value==temp->value)
return;
else if(node->value>temp->value&&temp->right==NULL)
{
temp->right=node;
return;
}
else if(node->value>temp->value)
{
temp=temp->right;
}
else if(node->value<temp->value&&temp->left==NULL)
{
temp->left=node;
return;
}
else if(node->value<temp->value)
{
temp=temp->left;
}
}
}
}
void inorder(TreeNode* r)
{
	if(r==NULL)
return;
else{
inorder(r->left);
cout<<r->value<<" ";
inorder(r->right);
}
}
TreeNode* minValueNode(TreeNode* r)
{
if(r==NULL)
return r;
TreeNode* curr = r;
while(curr->left!=NULL)
{
curr=curr->left;
}
return curr;
}
TreeNode* erase(TreeNode* r,int key)
{
if(r==NULL)
return r;
if(key>r->value)
{
r->right=erase(r->right,key);
}
else if(key<r->value)
{
r->left=erase(r->left,key);
}
else{
if(r->left==NULL)
{
TreeNode* temp=r->right;
delete r;
return temp;
}
else if(r->right==NULL)
{
TreeNode* temp=r->left;
delete r;
return temp;
}
else{
TreeNode* temp=minValueNode(r->right);
r->value=temp->value;
r->right=erase(r->right,temp->value);
}
}
return r;
}
};
int main()
{
BST my_bst;
TreeNode* temp=new TreeNode(51);
my_bst.insert(temp);
temp=new TreeNode(29);
my_bst.insert(temp);
temp=new TreeNode(68);
my_bst.insert(temp);
temp=new TreeNode(90);
my_bst.insert(temp);
temp=new TreeNode(36);
my_bst.insert(temp);
temp=new TreeNode(40);
my_bst.insert(temp);
temp=new TreeNode(22);
my_bst.insert(temp);
temp=new TreeNode(59);
my_bst.insert(temp);
temp=new TreeNode(44);
my_bst.insert(temp);
temp=new TreeNode(99);
my_bst.insert(temp);
temp=new TreeNode(77);
my_bst.insert(temp);
temp=new TreeNode(60);
my_bst.insert(temp);
temp=new TreeNode(83);
my_bst.insert(temp);
temp=new TreeNode(15);
my_bst.insert(temp);
temp=new TreeNode(75);
my_bst.insert(temp);
temp=new TreeNode(3);
my_bst.insert(temp);
cout<<" Before Insertion the binary search tree looks like:\n\n ";
my_bst.inorder(my_bst.root);
cout<<"\n";
cout<<"\n Now inserting 33, 88, 1, 36\n ";
temp=new TreeNode(33);
my_bst.insert(temp);
temp=new TreeNode(88);
my_bst.insert(temp);
temp=new TreeNode(1);
my_bst.insert(temp);
temp=new TreeNode(36);
my_bst.insert(temp);
cout<<"\n After insertion the binary search tree is\n\n ";
my_bst.inorder(my_bst.root);
cout<<"\n";
cout<<"\n Now deleting 44, 90, 68, 70\n ";
my_bst.root=my_bst.erase(my_bst.root,44);
my_bst.root=my_bst.erase(my_bst.root,68);
my_bst.root=my_bst.erase(my_bst.root,90);
my_bst.root=my_bst.erase(my_bst.root,70);
cout<<"\n After deletion the binary search tree is:\n\n ";
my_bst.inorder(my_bst.root);
cout<<"\n\n";
delete temp;
return 0;
}
