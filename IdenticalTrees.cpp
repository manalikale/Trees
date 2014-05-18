/*
Algorithm to check if two trees are identical
 
 Algorithm:
 sameTree(tree1, tree2)
 1. If both trees are empty then return 1.
 2. Else If both trees are non -empty
 (a) Check data of the root nodes (tree1->data ==  tree2->data)
 (b) Check left subtrees recursively  i.e., call sameTree(
 tree1->left_subtree, tree2->left_subtree)
 (c) Check right subtrees recursively  i.e., call sameTree(
 tree1->right_subtree, tree2->right_subtree)
 (d) If a,b and c are true then return 1.
 3  Else return 0 (one is empty and other is not)
 
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

int areIdenticalTrees(node *root1, node *root2)
{
    //if both trees are empty
    if(root1==NULL &&root2==NULL)
    {
        return 1;
    }
    
    //if both are non empty compare them
    if(root1!=NULL && root2!=NULL)
    {
        return (root1->data==root2->data && areIdenticalTrees(root1->left, root2->left) && areIdenticalTrees(root1->right, root2->right));
    }
    //one tree is empty and another is not
    return 0;
}

int main(void)
{
    node *root1=newnode(1);
    node *root2=newnode(1);
    cout<<areIdenticalTrees(root1, root2)<<endl;
    return 0;
}
