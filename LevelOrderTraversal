/*
Level Order Traversal
 
 Algo:
 
 For each node, first the node is visited and then it’s child nodes are put in a FIFO queue.
 printLevelorder(tree)
 1) Create an empty queue q
 2) temp_node = root //start from root
 3) Loop while temp_node is not NULL
    a) print temp_node->data.
    b) Enqueue temp_node’s children (first left then right children) to q
    c) Dequeue a node from q and assign it’s value to temp_node


 Queue is implemented using an array with maximum size of 500.
 
 Time: O(n)
 Sapce: O(n), since in the worst case all the nodes on the entire last level could be in the queue simulteneously
 */

#include<iostream>
#define MAX_Q_SIZE 500
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


node** createQueue(int *front, int *rear)
{
    node **queue =
    (node **)malloc(sizeof(struct node*)*MAX_Q_SIZE);
    
    *front = *rear = 0;
    return queue;
}

void enQueue(struct node **queue, int *rear, struct node *new_node)
{
    queue[*rear] = new_node;
    (*rear)++;
}

node *deQueue(struct node **queue, int *front)
{
    (*front)++;
    return queue[*front - 1];
}

void printLevelOrder(struct node* root)
{
    int rear, front;
    struct node **queue = createQueue(&front, &rear);
    struct node *temp_node = root;
    
    while(temp_node)
    {
        printf("%d ", temp_node->data);
        
        /*Enqueue left child */
        if(temp_node->left)
            enQueue(queue, &rear, temp_node->left);
        
        /*Enqueue right child */
        if(temp_node->right)
            enQueue(queue, &rear, temp_node->right);
        
        /*Dequeue node and make it temp_node*/
        temp_node = deQueue(queue, &front);
    }
}

int main(void)
{
    node *root=newnode(1);
    root->left=newnode(2);
    root->right=newnode(3);
    root->left->left=newnode(4);
    root->left->right=newnode(5);
    printLevelOrder(root);
    return 0;
}
