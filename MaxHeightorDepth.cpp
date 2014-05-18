/*
 Find the maximum height/depth of a binary tree
 
 Algorithm:
 Recursively calculate height of left and right subtrees of a node and assign height to a node as the max of the heights of two children plus 1(for the current node) i.e. max(maxDepth(root->left), maxDepth(root->right))+1
 
 Base case: If tree is empty return 0
 
 Example:
 
 maxDepth('1') = max(maxDepth('2'), maxDepth('3')) + 1
 = 2 + 1
 /    \
 /         \
 /             \
 /                 \
 /                     \
 maxDepth('1')                  maxDepth('3') = 1
 = max(maxDepth('4'), maxDepth('5')) + 1
 = 1 + 1   = 2
 /    \
 /        \
 /            \
 /                \
 /                    \
 maxDepth('4') = 1     maxDepth('5') = 1
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

int maxDepth(node *root)
{
    if(root==NULL)
        return 0;
    else
    {
        int ldepth=maxDepth(root->left);
        int rdepth=maxDepth(root->right);
        
        if(ldepth>rdepth)
        {
            return ldepth+1;
        }
        else
        {
            return rdepth+1;
        }
    }
}

int main(void)
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    cout<<maxDepth(root);
    cout<<endl;
    
    return 0;
}
