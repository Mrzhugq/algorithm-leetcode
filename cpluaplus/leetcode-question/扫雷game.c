#include<stdio.h>
#include<string.h> 
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define EASY_COUNT 10 //��ģʽ-10���� 

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
	//��ӡ�к�
	for(i=0;i<=col;i++)
	{
		printf("%d ",i);
	}
	printf("\n");
	for(i=1;i<=row;i++)
	{
		printf("%d ",i);//��ӡ�к� 
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
		int y=rand()%col+1;//�������һ������Ӷ������� 
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
        	mine[x][y+1]+mine[x-1][y+1]-8*'0';//ת��Ϊ���ּ�����������ΧһȦ�׵ĸ��� 
}

void FindMine(char mine[ROWS][COLS],char show[ROW][COLS],int row,int col)
{
	int x=0;
	int y=0;
	int win=0; 
	while(win<row*col-EASY_COUNT) //win<9*9-10(71)
	{
		printf("������Ҫ�Ų��׵���Ϣ(�к� �к�):>");
	    scanf("%d%d",&x,&y);
	    if(x>=1 && x<=row && y>=1 && y<=col)//�ж����������Ƿ�Ϸ� 
	    {
	    	//1.���� 
	    	if(mine[x][y]=='1')
	    	{
	    		printf("���ź����㱻ը���ˣ�\n");
	    		printf("�����ֲ����£�\n");
	    		DisplayBoard(mine,row,col);
	    		break;
			}
			//2.������
			else
			{
				//������x��y������Χ(x,y��һȦ)�м�����
				int count=Get_mine_count(mine,x,y); 
				show[x][y]=count+'0';//ת��Ϊ�ַ�����show 
				DisplayBoard(show,row,col);
				win++;
			} 
	    }
	    else
	    {
		    printf("��������Ƿ������������룡\n");
	    } 
	}
	if(win==row*col-EASY_COUNT)
	{
		printf("��ϲ�㣬���׳ɹ���\n");
		printf("�����ֲ����£�\n");
	    DisplayBoard(mine,row,col);
	}
}

void game()
{
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS]={0};  //11*11
	//2.�Ų��׵���Ϣ 
	char show[ROWS][COLS]={0};
	//��ʼ��
	InitBoard(mine,ROWS,COLS,'0'); 
	InitBoard(show,ROWS,COLS,'*'); 
	//��ӡ����
	//DisplayBoard(mine,ROW,COL);
	DisplayBoard(show,ROW,COL);
	//������
	SetMine(mine,ROW,COL); 
	//ɨ��
	FindMine(mine,show,ROW,COL); 
}

void test()
{
	int input=0;
	srand( (unsigned int)time(NULL) ); //��ʱ�����Ϊ�������ֵ��� 
	do
	{
	    menu();
	    printf("��ѡ��:>");
		scanf("%d",&input);
		switch(input)
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
			    break; 
			default:
				printf("ѡ�����������ѡ��\n");
				break;
		} 
	}while(input);
}

int main()
{
	test();
	return 0;
} 
