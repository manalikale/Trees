/*
Convert a binary tree into its mirror
 
 Algorithm - Mirror(tree):
 (1)  Call Mirror for left-subtree    i.e., Mirror(left-subtree)
 (2)  Call Mirror for right-subtree  i.e., Mirror(left-subtree)
 (3)  Swap left and right subtrees.
 temp = left-subtree
 left-subtree = right-subtree
 right-subtree = temp
 
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

void mirror(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        node *temp;
        mirror(root->left);
        mirror(root->right);
        temp=root->left;
        root->left=root->right;
        root->right=temp;
    }
}

void InorderPrint(node *root)
{
    if(root==NULL)
    {
        return;
    }
    else
    {
        InorderPrint(root->left);
        cout<<root->data;
        InorderPrint(root->right);
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
    cout<<"Original tree by inorder traversal is:"<<endl;
    InorderPrint(root);
    cout<<endl;
    mirror(root);
    cout<<endl;
    cout<<"Mirror tree is:"<<endl;
    InorderPrint(root);
    cout<<endl;
    return 0;
}
