#include<stdio.h>
#include<stdlib.h>
//栈结构(先进后出)

typedef struct
{
    int *data;
    //int data[100]
    int *mins; //存放最小值 
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
    
    //判断新加入的与前一个大小，如果前一个比刚加入的大，则把x赋给mins[]
	//如果前一个比刚加入的小，则把前一个赋给mins[]（即在加入时就求出了最小值） 
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
    Stack *s=CreateStack();//初始化

    PushStack(s,10);//压栈
    //s:[10]
    printf("%d\n",TopStrack(s));
    //10    TopStack()是返回栈最上面的数

    PushStack(s,20);
    printf("%d\n",TopStrack(s));

    PushStack(s,30);
    printf("%d\n",TopStrack(s));
    
    printf("当前最小值为%d\n",MinStack(s));

    PopStack(s);//出栈
    printf("%d\n",TopStrack(s));

    PopStack(s);
    printf("%d\n",TopStrack(s));

    DestoryStack(s);//释放空间
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

