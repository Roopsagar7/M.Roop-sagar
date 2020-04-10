#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int k; 
    struct node *left, *right; 
};  
struct node *newNode(int n) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->k = n; 
    temp->left = temp->right = NULL; 
    return temp; 
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->k); 
        inorder(root->right); 
    } 
} 
struct node* insert(struct node* node, int k) 
{ 
    if (node == NULL)
    return newNode(k); 
    if (k < node->k) 
        node->left  = insert(node->left, k); 
    else
        node->right = insert(node->right, k); 
    return node; 
} 
struct node * minValueNode(struct node* node) 
{ 
    struct node* current = node; 
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
struct node* deleteNode(struct node* root, int k) 
{
    if (root == NULL) return root; 
    if (k < root->k) 
        root->left = deleteNode(root->left, k); 
    else if (k > root->k) 
        root->right = deleteNode(root->right, k); 
    else
    { 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
        struct node* temp = minValueNode(root->right); 
        root->k = temp->k; 
        root->right = deleteNode(root->right, temp->k); 
    } 
    return root; 
} 
int main() 
{ 
   struct node *root = NULL; 
    root = insert(root, 29); 
    root = insert(root, 14); 
    root = insert(root, 07); 
    root = insert(root, 11); 
    root = insert(root, 01); 
    root = insert(root, 02); 
    root = insert(root, 05); 
    root = insert(root, 21);
  
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 14\n"); 
    root = deleteNode(root, 14); 
    printf("Inorder traversal of the given tree \n"); 
    inorder(root); 
  
    printf("\nDelete 11\n"); 
    root = deleteNode(root, 11); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 01\n"); 
    root = deleteNode(root, 01); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    printf("\nDelete 21\n"); 
    root = deleteNode(root, 21); 
    printf("Inorder traversal of the modified tree \n"); 
    inorder(root); 
  
    return 0; 
}