#include<stdio.h>
#include<stdlib.h> 

typedef char BTDataType;
typedef struct BinaryTreeNode
{
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
	int data;
}BTNode;

//1.ȫ�ֱ��� 
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

////2.������ 
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

//2.����˼��
//ÿ�����Ľڵ��������������������������Ľڵ��������Լ� 
int TreeSize(BTNode *root) 
{
	return root==NULL ? 0 : TreeSize(root->left)+TreeSize(root->right)+1;
}

int  TreeLeafSize(BTNode *root)//Ҷ�ӽڵ���� 
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
//	size=0;//ÿ�ε��� TreeSize��Ҫsize���㣬��Ϊsize��ȫ�ֱ�����������̫�� 
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
