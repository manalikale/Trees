/*
 Find the maximum diameter of a binary tree:The diameter of a tree is the number of nodes on the longest path between two leaves in the tree
 
 The diameter of a tree T is the largest of the following quantities:
 * the diameter of T’s left subtree  * the diameter of T’s right subtree  * the longest path between leaves that goes through the root of T (this can be computed from the heights of the subtrees of T)
 
 The implementation has been optimized by calculating the height in the same recursion rather than calling a height() separately.
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

int diameter(node *root, int *height)
{
    int left_height=0;
    int right_height=0;
    int left_diameter=0;
    int right_diameter=0;
    
    if(root==NULL)
    {
        *height=0;
        return 0;
    }
    
    /* Get the heights of left and right subtrees in left_height and right_height
     And store the returned values in ldiameter and ldiameter */
    left_diameter=diameter(root->left, &left_height);
    right_diameter=diameter(root->right, &right_height);
    
    /* Height of current node is max of heights of left and
     right subtrees plus 1*/
    
    *height=max(left_height, right_height)+1;
    
    return max(left_height+right_height+1,max(left_diameter, right_diameter));
    
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
    int height=0;
    cout<<diameter(root, &height);
    cout<<endl;
    
    return 0;
}
