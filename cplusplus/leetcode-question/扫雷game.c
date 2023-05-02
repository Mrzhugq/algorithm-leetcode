#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10 //简单模式-10个雷 

void menu()
{
	printf("***************************\n");
	printf("*******    1.play    ******\n");
	printf("*******    0.exit    ******\n");
	printf("***************************\n");
}

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j]=set;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS],int row,int col)
{
	int i,j;
	//打印列号
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		printf("%d ",i);//打印行号 
		for(j=1;j<=col;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS],int row,int col)
{
	int count=EASY_COUNT;
	while(count)
	{
		int x=rand()%row+1;
		int y=rand()%col+1;//随机产生一个坐标从而布置雷 
		if(board[x][y]=='0')
		{
			board[x][y]='1';
			count--;
		}
	}
}

int  Get_mine_count(char mine[ROWS][COLS],int x,int y)
{
	return  mine[x-1][y]+mine[x-1][y-1]+mine[x][y-1]+
	        mine[x+1][y-1]+mine[x+1][y]+mine[x+1][y+1]+
        	mine[x][y+1]+mine[x-1][y+1]-8*'0';//转化为数字加起来就是周围一圈雷的个数 
}

void FindMine(char mine[ROWS][COLS],char show[ROW][COLS],int row,int col)
{
	int x=0;
	int y=0;
	int win=0; 
	while(win<row*col-EASY_COUNT) //win<9*9-10(71)
	{
		printf("请输入要排查雷的信息(行号 列号):>");
	    scanf("%d%d",&x,&y);
	    if(x>=1 && x<=row && y>=1 && y<=col)//判断输入坐标是否合法 
	    {
	    	//1.是雷 
	    	if(mine[x][y]=='1')
	    	{
	    		printf("很遗憾，你被炸死了！\n");
	    		printf("雷区分布如下：\n");
	    		DisplayBoard(mine,row,col);
	    		break;
			}
			//2.不是雷
			else
			{
				//计算下x，y坐标周围(x,y外一圈)有几个雷
				int count=Get_mine_count(mine,x,y); 
				show[x][y]=count+'0';//转化为字符放入show 
				DisplayBoard(show,row,col);
				win++;
			} 
	    }
	    else
	    {
		    printf("输入坐标非法，请重新输入！\n");
	    } 
	}
	if(win==row*col-EASY_COUNT)
	{
		printf("恭喜你，排雷成功！\n");
		printf("雷区分布如下：\n");
	    DisplayBoard(mine,row,col);
	}
}

void game()
{
	//1.布置好的雷的信息
	char mine[ROWS][COLS]={0};  //11*11
	//2.排查雷的信息 
	char show[ROWS][COLS]={0};
	//初始化
	InitBoard(mine,ROWS,COLS,'0'); 
	InitBoard(show,ROWS,COLS,'*'); 
	//打印棋盘
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL); 
	//扫雷
	FindMine(mine,show,ROW,COL); 
}

void test()
{
	int input=0;
	srand( (unsigned int)time(NULL) ); //用时间戳作为生成随机值起点 
	do
	{
	    menu();
	    printf("请选择:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
			    break; 
			default:
				printf("选择错误，请重新选择\n");
				break;
		} 
	}while(input);
}

int main()
{
	test();
	return 0;
} 
