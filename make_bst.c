#include <stdio.h>
#include <stdlib.h>

struct BSTNode
{
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode *insert(struct BSTNode *root, int data)
{
    if (root == NULL)
    {
        root = (struct BSTNode *)malloc(sizeof(struct BSTNode));
        root->data = data;
        root->left = root->right = NULL;
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}
void inorder(struct BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inorder(root->left);
        printf("%d ,", root->data);
        inorder(root->right);
    }
}
void preorder(struct BSTNode *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ,", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main()
{
    // struct BSTNode *root = NULL;
    // root = insert(root, 7);
    // root = insert(root, 3);
    // root = insert(root, 9);
    // root = insert(root, 2);
    // root = insert(root, 4);
    // root = insert(root, 8);
    // root = insert(root, 12);
    // root = insert(root, 1);
    // root = insert(root, 5);
    // root = insert(root, 11);
    // root = insert(root, 13);
    struct BSTNode *head = NULL;
    printf("enter size ");
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        head =insert(head, s);
    }

    inorder(head);
    printf("\n");
    preorder(head);
    return 0;
}
