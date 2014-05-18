/*
 Delete a tree
 
 Algorithm: Postorder tree traversal(as it does work without storing anything): Delete the left child, then the right child and then the root
 
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

void deleteTree(node *root)
{
    if(root==NULL)
        return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
    cout<<"Deleting node: "<<root->data<<endl;
    
}

int main(void)
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    root->right->left=newnode(6);
    root->right->right=newnode(7);
    deleteTree(root);
    return 0;
}
