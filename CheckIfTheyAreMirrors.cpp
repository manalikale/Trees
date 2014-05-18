/*
Algorithm to check if two trees are mirrors of each other
 
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

int AreMirrors(node *root1, node *root2)
{
    if(root1==NULL && root2==NULL)
        return 1;
    if(root1==NULL || root2==NULL)
        return 0;
    if(root1->data!=root2->data)
        return 0;
    else
        return AreMirrors(root1->left, root2->right) && AreMirrors(root1->right, root2->left);
}



int main(void)
{

    node *root1=newnode(1);
    node *root2=newnode(1);
    root1->left=newnode(2);
    root2->right=newnode(2);
    root1->left->left=newnode(3);
    root2->right->right=newnode(3);
    cout<<AreMirrors(root1, root2)<<endl;
    return 0;
}
