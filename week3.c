#include <stdio.h>
#include <stdlib.h>
// Define a node structure
struct Node {
 int data;
 struct Node *left, *right;
};
// Function to create a new node
struct Node* createNode(int data) {
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 newNode->data = data;
 newNode->left = newNode->right = NULL;
 return newNode;
}
// Recursive function to insert a node
struct Node* insert(struct Node* root, int data) {
 if (root == NULL)
 return createNode(data);
 if (data < root->data)
 root->left = insert(root->left, data);
 else if (data > root->data)
 root->right = insert(root->right, data);
 return root;
}
// Function to find the minimum value node (used in deletion)
struct Node* findMin(struct Node* root) {
 while (root && root->left != NULL)
 root = root->left;
 return root;
}
// Recursive function to delete a node
struct Node* deleteNode(struct Node* root, int data) {
 if (root == NULL)
 return root;
 if (data < root->data)
 root->left = deleteNode(root->left, data);
 else if (data > root->data)
 root->right = deleteNode(root->right, data);
 else {
 // Case 1: No child
 if (root->left == NULL && root->right == NULL) {
 free(root);
 return NULL;
 }
 // Case 2: One child
 else if (root->left == NULL) {
 struct Node* temp = root->right;
 free(root);
 return temp;
 }
 else if (root->right == NULL) {
 struct Node* temp = root->left;
 free(root);
 return temp;
 }
 // Case 3: Two children
 struct Node* temp = findMin(root->right);
 root->data = temp->data;
 root->right = deleteNode(root->right, temp->data);
 }
 return root;
}
// Recursive Inorder Traversal
void inorder(struct Node* root) {
 if (root != NULL) {
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
 }
}
int main() {
 struct Node* root = NULL;
 // Insert nodes
 root = insert(root, 50);
 root = insert(root, 30);
 root = insert(root, 70);
 root = insert(root, 20);
 root = insert(root, 40);
 root = insert(root, 60);
 root = insert(root, 80);
 printf("Inorder Traversal of BST: ");
 inorder(root);
 printf("\n");
 // Delete some nodes
 root = deleteNode(root, 20);
 printf("After deleting 20: ");
 inorder(root);
 printf("\n");
 root = deleteNode(root, 30);
 printf("After deleting 30: ");
 inorder(root);
 printf("\n");
 root = deleteNode(root, 50);
 printf("After deleting 50: ");
 inorder(root);
 printf("\n");
 return 0;
}