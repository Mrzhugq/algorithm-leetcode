#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>


//全局变量 
long totalGrade = 0;
int T = 0;
int F = 0; 

//生成指定区间的随机数 
int myRand(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

//交换函数 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//print(int garde)
//{
//    printf("你该次得分为:%d\n", garde);
//	printf("你总得分为:%d\n", totalGrade);
//}

void add()
{
    system("cls");
    int a,b,i,sum,t=0,f=0;
    int loop = 0;
    printf("请输入你要猜的次数："); 
    scanf("%d", &loop); //输入循环次数 
	for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //生成[0, 10]区间的随机数 
	    b = myRand(0, 10);
        printf("%d + %d = ", a, b);
	    scanf("%d", &sum);
	    if(sum == a+b)
		{ 
		    system("color 07"); //一旦回答正确就恢复默认颜色 
			printf("回答正确!!!!\n");
		    t++;
		}
	    else
		{	system("color 06");
			printf("回答错误，请再接再厉。\n");
			f++;
		}
	}
    system("color 07"); 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("你该次得分为:%d\n", tempGarde);
	printf("你总得分为:%d\n", totalGrade);
}



void sub()
{
    system("cls");
    int a,b,c,i,jian,t=0,f=0;
    int loop = 0;
    printf("请输入你要猜的次数："); 
    scanf("%d", &loop); //输入循环次数 
    for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //生成[0, 10]区间的随机数 
	    b = myRand(0, 10);
		if(a < b) //让结果不能是负数 
		{ 
		    swap(&a, &b); 
		}
		printf("%d - %d = ", a, b);
		scanf("%d", &jian);
	    if(jian == a - b)
		{
		    system("color 07"); //一旦回答正确就恢复默认颜色 
		  	printf("回答正确!!!!\n");
		  	t++;
		}
	    else
	    { 
	    	system("color 04");
			printf("回答错误，请再接再厉。\n");
	   		f++;
		}
	} 
	system("color 07"); //颜色恢复默认 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("你该次得分为:%d\n", tempGarde);
	printf("你总得分为:%d\n", totalGrade);
}



void mul()
{
    system("cls");
	int a,b,i,cheng,t=0,f=0;
    int loop = 0;
    printf("请输入你要猜的次数："); 
    scanf("%d", &loop); //输入循环次数 
	for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //生成[0, 10]区间的随机数 
	    b = myRand(0, 10);
        printf("%d * %d = ", a, b);
	    scanf("%d", &cheng);
	    if(cheng == a * b)
		{ 
			system("color 07");
			printf("回答正确!!!!\n");
		    t++;
		}
	    else
		{
			system("color 05");
			printf("回答错误，请再接再厉。\n");
			f++;
		}
	}
	system("color 07"); //恢复默认 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("你该次得分为:%d\n", tempGarde);
	printf("你总得分为:%d\n", totalGrade);
}



void div()
{
	system("cls");
	int a, b, c, i, chu, t=0, f=0;
    int loop = 0;
    printf("请输入你要猜的次数："); 
    scanf("%d", &loop); //输入循环次数 
	for(i = 1; i <= loop; i++)
	{
		//保证整整除
		b = rand() % 10 + 1;       //生成[1, 10]区间的随机数 ,注意除数不能为零 
	    a = b * myRand(0, 10);   
	    while(a / b > 10)          //保证结果在10以内 
	    {
	    	a -= b; 
		}
		
		printf("%d ÷ %d = ", a, b);
		scanf("%d", &chu);
		if(chu == a / b)
		{
			system("color 07"); //改为默认 
			printf("回答正确!!!!\n");
			t++;
		}
		else
		{
			system("color 02"); //绿色 
			printf("回答错误，请再接再厉。\n");
			f++;
		}
	}
	system("color 07"); //恢复默认 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("你该次得分为:%d\n", tempGarde);
	printf("你总得分为:%d\n", totalGrade);
}



int main()
{
	srand(time(NULL));
	char c;
	int i;
	char user[10];
	char password[6];
	printf("计算机与信息工程学院\n");
    printf("20级科技1班\n");
	printf("朱国庆\n\n");
	printf("请输入用户名：\n");
	scanf("%s", user);
	printf("请输入密码：\n");
	for(i = 0; i < 7; i++)
    {
		password[i] = getch();
		printf("*"); 
		if(password[i] == '\r')
        {            
			password[i] = '\0';
			printf("\n");
            break;
		}
	}
	
	if(strcmp(user, "a") == 0 && strcmp(password, "1") == 0)
	{ 
		while(1)
		{
			printf("小学生四则运算程序\n");  //有点小bug每次输入选项的时候都要输入两次 
			printf("****A加法****\n");
			printf("****B减法****\n");
			printf("****C乘法****\n");
			printf("****D除法****\n");
			printf("****E退出****\n");
			getch(); 
			c = getchar();
			switch(c)
            {
                case'a':
				case'A':
				add();
				break;
				
				case'b':
				case'B':
				sub();
				break;
				
				case'c':
				case'C':
				mul();
				break;
				
				case'd':
				case'D':
				div();
				break;
				
				case'e':
				case'E':
				{
					system("cls");
					printf("你本次总体答对的题数个数为：%d\n", T);
					printf("你本次总体答错的题数个数为：%d\n", F);
					printf("按任意键继续");
					getch();
	 		        return 0;
				} 
				break;
				
				default:printf("请重选:");
				system("cls");
			}
		}
	} 
	else
	{
		printf("用户名或密码错误!\n");
	} 
	getch(); //按任意键继续 
	return 0; 
}
