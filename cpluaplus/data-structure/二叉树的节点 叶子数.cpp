#include<stdio.h>
#include<stdlib.h> 

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	int data;
}BTNode;

//1.全局变量 
//int size=0;
//void TreeSize(BTNode *root)
//{
//	if(root==NULL)
//	{
//		return;
//	}
//	else
//	{
//		size++;
//	}
//	TreeSize(root->left);
//	TreeSize(root->right);
//} 

////2.传参数 
//void  TreeSize(BTNode *root,int *psize)
//{
//	if(root==NULL)
//	{
//		return;
//	}
//	else
//	{
//		(*psize)++;
//	}
//	TreeSize(root->left,psize);
//	TreeSize(root->right,psize);
//} 

//2.分治思想
//每个树的节点数等于它的左子树和右子树的节点数加上自己 
int TreeSize(BTNode *root) 
{
	return root==NULL ? 0 : TreeSize(root->left)+TreeSize(root->right)+1;
}

int  TreeLeafSize(BTNode *root)//叶子节点个数 
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	
	return TreeLeafSize(root->left)+TreeLeafSize(root->right);
	//return root->left==NULL && root->left==NULL ? 1 : TreeLeafSize(root->left)+TreeLeafSize(root->right);
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
	
//	TreeSize(A);
//	printf("%d\n",size);
//	size=0;//每次调用 TreeSize都要size归零，因为size是全局变量，这样不太好 
//	TreeSize(B);
//	printf("%d\n",size);

//  int Asize=0;
//	TreeSize(A,&Asize);
//	printf("%d\n",Asize);
//	int Bsize=0;
//	TreeSize(B,&Bsize);
//	printf("%d\n",Bsize);

	printf("%d\n",TreeSize(A));
	printf("%d\n",TreeSize(B));
	
	printf("%d\n",TreeLeafSize(A));

} 
