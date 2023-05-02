#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<stdbool.h>

typedef struct Postion
{
	int row;
	int col;
}PT;

typedef PT STDataType;
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




//---------------------------------------------------------
//--------------------------------------上面是C语言栈的实现
//---------------------------------------------------------
//typedef struct Postion  //这个上面有啦
//{
//	int row;
//	int col;
//}PT;

void PrintMaze(int **maze, int N, int M)//打印
{
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<M; j++)
		{
			printf("%d ",maze[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

bool IsPass(int **maze, int N, int M, PT pos)//判断是否可通
{
	if(pos.row>=0 && pos.row<N 
	  && pos.row>=0 && pos.col<M 
	  && maze[pos.row][pos.col] == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ST path;//创建一个栈,储存通路路径坐标

bool GetMazePath(int **maze, int N, int M, PT cur)
{
	StackPush(&path, cur);
	
	//如果走到出口
	if(cur.row == N-1 && cur.col == M-1)
	{
		return true;
	}
	//探测cur位置的上下左右四个方向
	PT next;
	maze[cur.row][cur.col] = 2; //标记为2，代表已经走过，防止走回去
	  
	//上
	next = cur;
	next.row-=1;
	if(IsPass(maze, N, M, next))
	{
		if(GetMazePath(maze, N, M, next) == true)//已经找到一个通路了下面的就不用递归了直接return就好
		{
			return true;
		}
	}
	
	//下
	next = cur;
	next.row+=1;
	if(IsPass(maze, N, M, next))
	{
		if(GetMazePath(maze, N, M, next) == true)
		{
			return true;
		}
	}
	
	//左
	next = cur;
	next.col-=1;
	if(IsPass(maze, N, M, next))
	{
		if(GetMazePath(maze, N, M, next) == true)
		{
			return true;
		}
	}
	
	//右
	next = cur;
	next.col+=1;
	if(IsPass(maze, N, M, next))
	{
		if(GetMazePath(maze, N, M, next) == true)
		{
			return true;
		}
	}
	
	StackPop(&path);
	return false;//死路返回false
}

//打印栈里面的路径坐标 -> 但是栈存储的是反着的坐标，所以要反着打印 -> 在入一次栈(倒一下)
void printPath(ST* ps)
{
	ST rPath;//存储反过来的坐标
	StackInit(&rPath);//初始化rPath
	
	while(!StackEmpty(&path))
	{
	    PT ret = StackTop(&path);
	    StackPush(&rPath, ret);
	    StackPop(&path);
	}
	
	while(!StackEmpty(&rPath))
	{
		PT res = StackTop(&rPath);
		printf("(%d,%d)\n", res.row,res.col);
		StackPop(&rPath);
	}
	StackDestory(&rPath);//释放rPath
}

int main()
{
	int N=0;
	int M=0;
	while(scanf("%d%d",&N,&M) != EOF)//多组输入
	{
		//动态开辟二维数组
		//int arr[N][M]=0;  C99才支持这样写
		int **maze = (int**)malloc(sizeof(int*) * N);
		for(int i=0; i<N; i++)
		{
			maze[i] = (int*)malloc(sizeof(int) * M);
		}
		//二维数组输入
		for(int i=0; i<N; i++)
		{
			for(int j=0; j<M; j++)
			{
				scanf("%d",&maze[i][j]);
			}
		}
		//打印调试
		//PrintMaze(maze, N, M);
		
		//查找路
		StackInit(&path);//初始化path
		PT entry = {0, 0};
		bool result = GetMazePath(maze, N, M, entry);
		if(result == true)
		{
			//找到通路啦
			printPath(&path);//打印通路路径的坐标
		}
		else
		{
			printf("没找到通路\n");
		}
		//释放
		StackDestory(&path);
		for(int i=0; i<N; i++)
		{
			free(maze[i]);
		}
		free(maze);
		maze=NULL;
	}
}