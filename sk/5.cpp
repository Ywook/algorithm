#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode{
    int data;
    TreeNode *left, *right;
}TreeNode;

void inorder(TreeNode *cur){
    if(cur != NULL){
        inorder(cur->left);
        printf("%d ", cur->data);
        inorder(cur->right);
    }
}

void preorder(TreeNode * cur){
    if (cur != NULL)
    {
        printf("%d ", cur->data);
        preorder(cur->left);
        preorder(cur->right);
    }
}

void postorder(TreeNode *cur){
    if (cur != NULL)
    {
        postorder(cur->left);
        postorder(cur->right);
        printf("%d ", cur->data);
    }
}

void appendNode(TreeNode *cur, int data, int left){
    TreeNode *newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if(left){
        while(cur->left != NULL){
            cur = cur->left;
        }
        cur->left = newNode;
    }else{
        while(cur->right != NULL){
            cur =cur->right;
        }
        cur->right = newNode;
    } 
}
int main()
{
    int i;
    TreeNode *root = (TreeNode*) malloc(sizeof(TreeNode));

    root->data = 1;
    root->left = root->right = NULL;

    appendNode(root, 2, 1);
    appendNode(root, 4, 1);
    appendNode(root, 3, 0);
    appendNode(root->right, 5, 1);
    appendNode(root, 6, 0);
    appendNode(root, 7, 0);


    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}