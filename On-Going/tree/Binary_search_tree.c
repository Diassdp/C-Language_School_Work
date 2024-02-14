#include<stdlib.h>
#include<stdio.h>
struct bst {
int data;
struct bst * right, * left;
};
typedef struct bst node;

void insert(node ** tree, int val)
{
 node *temp = NULL;
 if(!(*tree))
 {
 temp = (node *)malloc(sizeof(node));
 temp->left = temp->right = NULL;
 temp->data = val;
 *tree = temp;
 return;
 }
 
 if(val < (*tree)->data)
 {
 insert(&(*tree)->left, val);
 }
 
 else if(val > (*tree)->data)
 {
 insert(&(*tree)->right, val);
 }
 
}

void print_preorder(node * tree)
{
 if (tree)
 {
 printf("%d\n",tree->data);
 print_preorder(tree->left);
 print_preorder(tree->right);
 }
}

void print_inorder(node * tree)
{
 if (tree)
 {
 print_inorder(tree->left);
 printf("%d\n",tree->data);
 print_inorder(tree->right);
 }
}

void print_postorder(node * tree)
{
 if (tree)
 {
 print_postorder(tree->left);
 print_postorder(tree->right);
 printf("%d\n",tree->data);
 }
}

void deltree(node * tree)
{
 if (tree)
 {
 deltree(tree->left);
 deltree(tree->right);
 free(tree);
 }
}
node* search(node ** tree, int val)
{
 if(!(*tree))
 {
 return NULL;
 }
 if(val < (*tree)->data)
 {
 search(&((*tree)->left), val);
 }
 else if(val > (*tree)->data)
 {
 search(&((*tree)->right), val);
 }
 else if(val == (*tree)->data)
 {
 return *tree;
 }
}

int main()
{
int i,A[30] = {7131, 4785, 8820, 654, 2306, 3029, 6587, 5371, 2069, 7816, 8119,
3096, 6909, 697, 3764, 3756, 6115, 8477, 9594, 8856, 3741, 8500, 8693, 1090,
7461, 3007, 1162, 6303, 6279, 3310};
 node *root;
 node *tmp;
 
 //int i;
 root = NULL;
 for(i=0;i<3;i++)
 {
 	insert(&root,A[i]);
 }
 /* Inserting nodes into tree */
 
 /* Printing nodes of tree */
 printf("Pre Order Display\n");
 print_preorder(root);
 printf("In Order Display\n");
 print_inorder(root);
 printf("Post Order Display\n");
 print_postorder(root);
 /* Search node into tree */
 /*
 				7131
 			   /  \
 		       4785 8820
 			  /    
 			 654
			  \
			  2306
			  	\  
			  	3029
 			*/
 tmp = search(&root, 15);
 if (tmp)
 {
 printf("Searched node=%d\n", tmp->data);
 }
 else
 {
 printf("Data Not found in tree.\n");
 }
 /* Deleting all nodes of tree */
 deltree(root);
}
