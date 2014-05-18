/*
Calculate the size of a tree i.e. the number of elements present in a tree
 
 Size of tree=size of left subtree + size of right subtree+1
 Time Complexity: O(n)
 Auxiliary Space: O(n)
 */

#include<iostream>

using namespace std;

struct node{
    
    int data;
    node *left;
    node *right;
};

node *newnode(int data)
{
    node *newnode=new node();
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

int size(node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        return (size(root->left)+size(root->right)+1);
    }
}

int main(void)
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(8);
    root->right->right=newnode(9);
    cout<<size(root);
    cout<<endl;
    
    return 0;
}
