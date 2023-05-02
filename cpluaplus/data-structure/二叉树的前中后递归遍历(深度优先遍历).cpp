#include<stdio.h>
#include<stdlib.h> 

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	int data;
}BTNode;

void  PrevOrder(BTNode *root)//前序 
{
	if(root==NULL)
	{
		printf("NULL ");
		return;
	}
	
	printf("%c ",root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void  InOrder(BTNode *root)//中序 
{
	if(root==NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%c ",root->data);
	InOrder(root->right);
}

void  PostOrder(BTNode *root)//后序 
{
	if(root==NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ",root->data);
}

void DestoryTree(BTNode *root)//后序遍历释放 
{
	if(root==NULL) 
	{
		return;
	}
	DestoryTree(root->left);
	DestoryTree(root->right);
	free(root);
}


int main()
{
	BTNode *A=(BTNode*)malloc(sizeof(BTNode)*1);
	A->data='A';
	A->left=NULL;
	A->right=NULL;
	
	BTNode *B=(BTNode*)malloc(sizeof(BTNode)*1);
	B->data='B';
	B->left=NULL;
	B->right=NULL;
	
	BTNode *C=(BTNode*)malloc(sizeof(BTNode)*1);
	C->data='C';
	C->left=NULL;
	C->right=NULL;
	
	BTNode *D=(BTNode*)malloc(sizeof(BTNode)*1);
	D->data='D';
	D->left=NULL;
	D->right=NULL;
	
	BTNode *E=(BTNode*)malloc(sizeof(BTNode)*1);
	E->data='E';
	E->left=NULL;
	E->right=NULL;
	
	A->left=B;
	A->right=C;
	B->left=D;
	B->right=E;
	//PrevOrder(A);
	//InOrder(A);
	PostOrder(A);
	printf("\n");
} 
