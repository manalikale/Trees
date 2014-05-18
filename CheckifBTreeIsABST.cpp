/*
Algorithm to check if a binary tree is a binary search tree
 
 Algorithm:
 A binary search tree (BST) is a node based binary tree data structure which has the following properties.  • The left subtree of a node contains only nodes with keys less than the node’s key.  • The right subtree of a node contains only nodes with keys greater than the node’s key.  • Both the left and right subtrees must also be binary search trees.

 
 The trick is to write a utility helper function isBSTUtil(node* node, int min, int max) that traverses down the tree keeping track of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN and INT_MAX — they narrow from there.
 
 Time: O(n)
 Sapce: O(n)
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


int isBSTUtil(node *root, int min, int max)
{
    if(root==NULL)
    {
        return 1;
    }
    
    if(root->data<min || root->data>max)
    {
        return 0;
    }
    
    return
    isBSTUtil(root->left, min, root->data-1) && isBSTUtil(root->right, root->data+1, max);
}

int isBST(node *root)
{
    return isBSTUtil(root, INT_MIN,INT_MAX);
}

int main(void)
{
    node *root=newnode(10);
    root->left=newnode(5);
    root->right=newnode(11);
    
    if(isBST(root))
        cout<<"Is BST"<<endl;
    else
        cout<<"Not BST"<<endl;
    return 0;
}
