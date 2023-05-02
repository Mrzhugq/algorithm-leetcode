#include<stdio.h>
#include<stdlib.h>
//ջ�ṹ(�Ƚ����)

typedef struct
{
    int *data;
    //int data[100]
    int *mins; //�����Сֵ 
    int size;
} Stack;

Stack* CreateStack()
{
    Stack *s=(Stack*)malloc(sizeof(Stack));
    s->data=NULL;
    s->mins=NULL;
    s->size=0;
    return s;
}

void PushStack(Stack* s,int x)
{
    s->data=(int*)realloc(s->data,sizeof(int)*(s->size+1));
    s->mins=(int*)realloc(s->mins,sizeof(int)*(s->size+1));
    s->data[s->size]=x;
    
    //�ж��¼������ǰһ����С�����ǰһ���ȸռ���Ĵ����x����mins[]
	//���ǰһ���ȸռ����С�����ǰһ������mins[]�����ڼ���ʱ���������Сֵ�� 
    if(s->size==0 || s->mins[s->size-1]>x)
    {
    	s->mins[s->size]=x;
	}
	else
	{
		s->mins[s->size]=s->mins[s->size-1];
	}
    
    s->size++;
}

void PopStack(Stack* s)
{
    s->size--;
}

int TopStrack(const Stack* s)
{
    return s->data[(s->size)-1];
}

int MinStack(Stack* s)
{
	return s->mins[(s->size)-1]; 
}

void DestoryStack(Stack *s)
{
    free(s->data);
    free(s->mins);
    free(s);
}

PrintStack(Stack* s)
{
    for(int i=0; i<(s->size); i++)
    {
        printf("%d\n",s->data[i]);
    }

}
int main()
{
    Stack *s=CreateStack();//��ʼ��

    PushStack(s,10);//ѹջ
    //s:[10]
    printf("%d\n",TopStrack(s));
    //10    TopStack()�Ƿ���ջ���������

    PushStack(s,20);
    printf("%d\n",TopStrack(s));

    PushStack(s,30);
    printf("%d\n",TopStrack(s));
    
    printf("��ǰ��СֵΪ%d\n",MinStack(s));

    PopStack(s);//��ջ
    printf("%d\n",TopStrack(s));

    PopStack(s);
    printf("%d\n",TopStrack(s));

    DestoryStack(s);//�ͷſռ�
    return 0;

}


//MinStack()

//push(s,10)
//data: [10]
//mins: [10]
//
//push(s,20)
//data: [10,20]
//mins: [10,10] 
//
//push(s,5)
//data: [10,20,5]
//mins: [10,10,5]
//
//pop(s)
//data: [10,20]
//mins: [10,10]
//
//push(s,15)
//data: [10,20,15]
//mins: [10,10,10]

