Experiment 11:-
Aim:-To write a C program to construct a Binary Search Tree (BST) by inserting a
sequence of elements, and to traverse it using in-order, pre-order, and post-order
traversal techniques.
Algorithm
1. Define a structure Node with a data field and left and right child pointers.
2. To insert a value: if the tree (or subtree) is empty, create a new node there;
if the value is smaller than the current node's data, insert it into the left
subtree; if larger, insert it into the right subtree.
3. For in-order traversal: recursively traverse the left subtree, visit (print) the
current node, then recursively traverse the right subtree.
4. For pre-order traversal: visit (print) the current node, then recursively
traverse the left subtree, then the right subtree.
5. For post-order traversal: recursively traverse the left subtree, then the right
subtree, then visit (print) the current node.
6. Read a set of values from the user, insert each into the BST, and display
the results of all three traversals.
Program
#include <stdio.h>
#include <stdlib.h>
struct Node {
 int data;
 struct Node *left, *right;
};
struct Node *createNode(int value) {
 struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));
 newNode->data = value;
 newNode->left = newNode->right = NULL;
 return newNode;
}
struct Node *insert(struct Node *root, int value) {
 if (root == NULL)
 return createNode(value);
 if (value < root->data)
 root->left = insert(root->left, value);
 else if (value > root->data)
 root->right = insert(root->right, value);
 return root;
}
void inorder(struct Node *root) {
 if (root == NULL) return;
 inorder(root->left);
 printf("%d ", root->data);
 inorder(root->right);
}
void preorder(struct Node *root) {
  if (root == NULL) return;
 postorder(root->left);
 postorder(root->right);
 printf("%d ", root->data);
}
int main() {
 struct Node *root = NULL;
 int n, value;
 printf("Enter number of nodes: ");
 scanf("%d", &n);
 printf("Enter %d values: ", n);
 for (int i = 0; i < n; i++) {
 scanf("%d", &value);
 root = insert(root, value);
 }
 printf("\nIn-order traversal: ");
 inorder(root);
 printf("\nPre-order traversal: ");
 preorder(root);
 printf("\nPost-order traversal: ");
 postorder(root);
 printf("\n");
 return 0;
}
