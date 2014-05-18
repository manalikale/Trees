/*
Print all root to leaf nodes paths one per line
 
 Algo:
 Traverse the nodes of a tree in preorder(root,left subtree and right subtree recursively)
 
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

void printArray(int path[],int pathlen)
{
    int i=0;
    for(i=0;i<pathlen;i++)
    {
        cout<<" "<<path[i];
    }
    cout<<endl;
}
void printPathsRecur(node *root, int path[],int pathlen)
{
    if(root==NULL)
    {
        return;
    }
    
    //append this node to the path array
    path[pathlen]=root->data;
    pathlen++;
    
    //if its a leaf node print it out
    if(root->left==NULL && root->right==NULL)
    {
        printArray(path, pathlen);
    }
    else
    {
        //try both the subtrees
        printPathsRecur(root->left, path, pathlen);
        printPathsRecur(root->right, path, pathlen);
    }
}

void printPaths(node *root)
{
    int path[1000];
    printPathsRecur(root, path, 0);
}

int main(void)
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printPaths(root);
    return 0;
}
