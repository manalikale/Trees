/*
Print ancestors of a given node in a binary tree
 
 
 Time: O(n)
 Sapce: O(n)
 */

#include <iostream>
#include <stack>
using namespace std;

// Binary Tree node
struct node
{
    int data;
    struct node *left, *right;
};

bool printAncestors(node *root, int key)
{
    if(root==NULL)
    {
        return false;
    }
    if(root->data==key)
    {
        return true;
    }
    
    //If target is present in either left or right subtree print the node
    if(printAncestors(root->left, key)|| printAncestors(root->right, key))
    {
        cout<<root->data<<" ";
        return true;
    }
    else
        return false;
}
// A utility functiont to create a new node
struct node* newNode(int data)
{
    struct node* node = new struct node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return(node);
}

int main()
{
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(7);
    root->left->right = newNode(6);
    root->right->left  = newNode(5);
    root->right->right = newNode(4);
    printAncestors(root, 7);
    return 0;
}
