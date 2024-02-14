// C program to demonstrate insert
// operation in binary
// search tree.
#include <stdio.h>
#include <stdlib.h>
struct node {
int key;
struct node *left, *right;
};

// A utility function to create a new BST node
struct node* newNode(int item){
struct node* temp = (struct
node*)malloc(sizeof(struct node));
temp->key = item;
temp->left = temp->right = NULL;
return temp;
}
// A utility function to do inorder traversal of BST

//Print Function inorder//
void inorder(struct node* root){
if (root != NULL) {
inorder(root->left);
printf("%d \n", root->key);
inorder(root->right);
}
}
//Print Function preorder//
void preorder(struct node * root)
{
 if (root)
 {
 printf("%d\n",root->key);
 preorder(root->left);
 preorder(root->right);
 }
}

//Print Function postorder//
void postorder(struct node * root)
{
 if (root)
 {
 postorder(root->left);
 postorder(root->right);
 printf("%d\n",root->key);
 }
}

/* A utility function to insert
a new node with given key in
* BST */
struct node* insert(struct node* node, int key){
/* If the tree is empty, return a new node */
if (node == NULL)
return newNode(key);
/* Otherwise, recur down the tree */
if (key < node->key)
node->left = insert(node->left, key);
else if (key > node->key)
node->right = insert(node->right, key);
/* return the (unchanged) node pointer */
return node;
}
// Driver Code
int main()
{
int choice;
struct node* root = NULL;
while(1)
{
printf("[MENU BINARY TREE]\n");
printf("1.Masukan Data Kedalam Tree\n");
printf("2.Print Binary Tree\n");
printf("3.Exit\n");
printf("Masukan Pilihan:");scanf("%d",&choice);
switch(choice)
{
	case 1:{
		int input_t;
		printf("\nData Yang Dimasukan:");scanf("%d",&input_t);
		root = insert(root,input_t);
		break;
	}
	case 2:{
		printf("[PRE ORDER]\n");preorder(root);
		printf("[IN ORDER]\n");inorder(root);
		printf("[POST ORDER]\n");postorder(root);
		break;
	}
	case 3:{
		exit(0);break;
	}
	default:{
		printf("[PILIHAN TIDAK ADA DALAM MENU]\n");
		break;
	}
}

}
}
