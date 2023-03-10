/*
 * Program  : Binary Search Tree insertion
 * Language : C
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
};

//this function will return the new node with the given value
struct node *getNewNode(int val)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->key   = val;
    newNode->left  = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node *insert(struct node *root, int val)
{
    /*
     * It will handle two cases,
     * 1. if the tree is empty, return new node in root
     * 2. if the tree traversal reaches NULL, it will return the new node
     */
    if(root == NULL)
        return getNewNode(val);
    /*
     * if given val is greater than root->key,
     * we should find the correct place in right subtree and insert the new node
     */
    if(root->key < val)
        root->right = insert(root->right,val);
    /*
     * if given val is smallar than root->key,
     * we should find the correct place in left subtree and insert the new node
     */
    else if(root->key > val)
        root->left = insert(root->left,val);
    /*
     * It will handle two cases
     * (Prevent the duplicate nodes in the tree)
     * 1.if root->key == val it will straight away return the address of the root node
     * 2.After the insertion, it will return the original unchanged root's address
     */
    return root;
}

/*
 * it will print the tree in ascending order
 * we will discuss about it in the upcoming tutorials
 */
void inorder(struct node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    printf("%d ",root->key);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if(root == NULL)
        return;
    printf("%d ",root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->key);

}

int main() {
    struct node *root = NULL;
    root = insert(root, 10);
 insert(root, 5);
 insert(root, 8);
 insert(root, 2);
 insert(root, 7);
 insert(root, 9);
 insert(root, 20);
 insert(root, 15);
 insert(root, 30);
 insert(root, 25);
 insert(root, 44);
    preorder(root);
    printf("\n") ;
    inorder(root);
    printf("\n") ;
    postorder(root);
        return 0;
}