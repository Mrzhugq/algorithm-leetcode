#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//ջ�ṹһ��������ʵ�ֱȽϺ� (ջ�ṹ�Ƚ����������߳�Ӱ��˳��) 
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;       //ջ�� 
	int capacity;  //�ռ� 
}ST;

void StackInit(ST *ps)//��ʼ�� 
{
	assert(ps);
	STDataType *temp=(STDataType*)malloc(sizeof(STDataType)*4);//�ȸ�4��������������
	if(temp==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->a=temp;
	ps->capacity=4;
	
	//ps->top=0;  //����topָ��ջ��Ԫ�ص���һ��λ��,�ȸ�ֵ��top++ 
	//ps->top=-1; //����topָ��ջ��Ԫ�أ���top++ �ڸ�ֵ
	
	ps->top=0;
}

void StackPush(ST *ps,STDataType x)//��ջ 
{
	assert(ps);
	if(ps->capacity == ps->top)//���� 
	{
		STDataType *temp=(STDataType* )realloc(ps->a,sizeof(int) * ps->capacity * 2);
		//һ�㶼��2��������
		if(temp==NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		else
		{
			ps->a=temp;
			ps->capacity=ps->capacity*2;
		}
	}
	
	ps->a[ps->top]=x;
	ps->top++; 
}

void StackPop(ST *ps)//��ջ 
{
	assert(ps);
	assert(ps->top > 0);//ջ�ղ��ܳ�ջ ֱ����ֹ���� 
	ps->top--;
}

STDataType StackTop(ST *ps)//ȡջ�������� 
{
	assert(ps);
	assert(ps->top > 0);//ջ�� ֱ����ֹ����
	return ps->a[ps->top-1];
}

int StackSize(ST *ps) //���ݸ��� 
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST *ps)//�ж��ǲ��ǿ� 
{
	assert(ps);
	return ps->top==0;
}



void StackDestory(ST *ps)//�ͷ� 
{
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity=ps->top=0;
}



int main()
{
	ST st;
	StackInit(&st);
	StackPush(&st,1);
	StackPush(&st,2);
	StackPush(&st,3);
	StackPush(&st,4);
	
	while(!StackEmpty(&st))//����ȥ������ֻ��������ɾ�߳� 
	{
		printf("%d ",StackTop(&st));
		StackPop(&st);
    }
    
	StackDestory(&st);
	return 0;
}
