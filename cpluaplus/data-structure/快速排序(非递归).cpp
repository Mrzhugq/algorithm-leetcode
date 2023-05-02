#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

//栈结构一般用数组实现比较好 (栈结构先进后出，边入边出影响顺序) 
typedef int STDataType;
typedef struct Stack
{
	STDataType *a;
	int top;       //栈顶 
	int capacity;  //空间 
}ST;

void StackInit(ST *ps)//初始化 
{
	assert(ps);
	STDataType *temp=(STDataType*)malloc(sizeof(STDataType)*4);//先给4个，不够在增容
	if(temp==NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	ps->a=temp;
	ps->capacity=4;
	
	//ps->top=0;  //这样top指向栈顶元素的下一个位置,先赋值在top++ 
	//ps->top=-1; //这样top指向栈顶元素，先top++ 在赋值
	
	ps->top=0;
}

void StackPush(ST *ps,STDataType x)//入栈 
{
	assert(ps);
	if(ps->capacity == ps->top)//满了 
	{
		STDataType *temp=(STDataType* )realloc(ps->a,sizeof(int) * ps->capacity * 2);
		//一般都是2倍的扩容
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

void StackPop(ST *ps)//出栈 
{
	assert(ps);
	assert(ps->top > 0);//栈空不能出栈 直接终止程序 
	ps->top--;
}

STDataType StackTop(ST *ps)//取栈顶的数据 
{
	assert(ps);
	assert(ps->top > 0);//栈空 直接终止程序
	return ps->a[ps->top-1];
}

int StackSize(ST *ps) //数据个数 
{
	assert(ps);
	return ps->top;
}

bool StackEmpty(ST *ps)//判断是不是空 
{
	assert(ps);
	return ps->top==0;
}

void StackDestory(ST *ps)//释放 
{
	assert(ps);
	free(ps->a);
	ps->a=NULL;
	ps->capacity=ps->top=0;
}



//---------------------------------------------------------------上面是栈的实现
//递归缺陷：
//1.递归要建立栈帧，消耗大（几十年前这个现在比较明显，现在几乎没了，
//因为现在CPU计算速度比以前快多了，而且内存也大多了，编译器优化也好了）
//2.递归在极端情况下可能会导致栈溢出（栈帧深度太深，栈空间不够用，可能会溢出）

//改非递归方式：
//1.直接改成循环（简单递归）
//2.借助数据结构栈模拟递归过程（复杂递归）

int PartSort(int *arr,int left,int right)//快排的单趟排序
{
	int bagin=left,end=right;
	int pivot=bagin;//坑
	int key=arr[bagin]; //关键字
	
	while(bagin < end)
	{
		//1.右边找小的放到左边
		while(bagin < end && arr[end] >= key)//arr[end] >= key 注意这里要>=否则会死循环
		{
			end--;
		}
		//小的放到左边的坑里
		arr[pivot]=arr[end];
		pivot=end;
		//2.左边找大的放到右边
		while(bagin < end && arr[bagin] <= key)
		{
			bagin++;
		}
		//大的放到右边的新坑里
		arr[pivot]=arr[bagin];
		pivot=bagin;
	}
	pivot=bagin;//pivot=end;
	arr[pivot]=key;
	
	return pivot;
}

void QuickSortNonR(int *arr,int Size)
{
	ST st;
	StackInit(&st);
	StackPush(&st,Size-1);//用栈来存储区间
	StackPush(&st,0);	
	
	while(!StackEmpty(&st))
	{
		int left=StackTop(&st);
		StackPop(&st);
		
		int right=StackTop(&st);
		StackPop(&st);
		
		int keyIndex=PartSort(arr,left,right);
		//[left,keyIndex-1] [keyIndex] [keyIndex+1,right]
		
		//如果想先处理左半边就先入右边区间，因为栈是先进后出
		if(keyIndex+1 < right)//keyIndex+1 < right表示区间还有多个数，需要再分
		{
			StackPush(&st,right);//这里同理因为要先拿左，所以要先入右
			StackPush(&st,keyIndex+1);	
		}
		if(left < keyIndex-1)
		{
			StackPush(&st,keyIndex-1);
			StackPush(&st,left);			
		}
	}
	
	StackDestory(&st);
}


int main()
{
	int arr[]={5,2,1,4,3,6,9,8,7,0};
    QuickSortNonR(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d ",arr[i]);
	} 
	return 0;
}