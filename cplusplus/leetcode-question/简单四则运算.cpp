#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>


//ȫ�ֱ��� 
long totalGrade = 0;
int T = 0;
int F = 0; 

//����ָ������������ 
int myRand(int min, int max)
{
	return (rand() % (max - min + 1) + min);
}

//�������� 
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//print(int garde)
//{
//    printf("��ôε÷�Ϊ:%d\n", garde);
//	printf("���ܵ÷�Ϊ:%d\n", totalGrade);
//}

void add()
{
    system("cls");
    int a,b,i,sum,t=0,f=0;
    int loop = 0;
    printf("��������Ҫ�µĴ�����"); 
    scanf("%d", &loop); //����ѭ������ 
	for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //����[0, 10]���������� 
	    b = myRand(0, 10);
        printf("%d + %d = ", a, b);
	    scanf("%d", &sum);
	    if(sum == a+b)
		{ 
		    system("color 07"); //һ���ش���ȷ�ͻָ�Ĭ����ɫ 
			printf("�ش���ȷ!!!!\n");
		    t++;
		}
	    else
		{	system("color 06");
			printf("�ش�������ٽ�������\n");
			f++;
		}
	}
    system("color 07"); 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("��ôε÷�Ϊ:%d\n", tempGarde);
	printf("���ܵ÷�Ϊ:%d\n", totalGrade);
}



void sub()
{
    system("cls");
    int a,b,c,i,jian,t=0,f=0;
    int loop = 0;
    printf("��������Ҫ�µĴ�����"); 
    scanf("%d", &loop); //����ѭ������ 
    for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //����[0, 10]���������� 
	    b = myRand(0, 10);
		if(a < b) //�ý�������Ǹ��� 
		{ 
		    swap(&a, &b); 
		}
		printf("%d - %d = ", a, b);
		scanf("%d", &jian);
	    if(jian == a - b)
		{
		    system("color 07"); //һ���ش���ȷ�ͻָ�Ĭ����ɫ 
		  	printf("�ش���ȷ!!!!\n");
		  	t++;
		}
	    else
	    { 
	    	system("color 04");
			printf("�ش�������ٽ�������\n");
	   		f++;
		}
	} 
	system("color 07"); //��ɫ�ָ�Ĭ�� 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("��ôε÷�Ϊ:%d\n", tempGarde);
	printf("���ܵ÷�Ϊ:%d\n", totalGrade);
}



void mul()
{
    system("cls");
	int a,b,i,cheng,t=0,f=0;
    int loop = 0;
    printf("��������Ҫ�µĴ�����"); 
    scanf("%d", &loop); //����ѭ������ 
	for(i = 1; i <= loop; i++)
	{
		a = myRand(0, 10); //����[0, 10]���������� 
	    b = myRand(0, 10);
        printf("%d * %d = ", a, b);
	    scanf("%d", &cheng);
	    if(cheng == a * b)
		{ 
			system("color 07");
			printf("�ش���ȷ!!!!\n");
		    t++;
		}
	    else
		{
			system("color 05");
			printf("�ش�������ٽ�������\n");
			f++;
		}
	}
	system("color 07"); //�ָ�Ĭ�� 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("��ôε÷�Ϊ:%d\n", tempGarde);
	printf("���ܵ÷�Ϊ:%d\n", totalGrade);
}



void div()
{
	system("cls");
	int a, b, c, i, chu, t=0, f=0;
    int loop = 0;
    printf("��������Ҫ�µĴ�����"); 
    scanf("%d", &loop); //����ѭ������ 
	for(i = 1; i <= loop; i++)
	{
		//��֤������
		b = rand() % 10 + 1;       //����[1, 10]���������� ,ע���������Ϊ�� 
	    a = b * myRand(0, 10);   
	    while(a / b > 10)          //��֤�����10���� 
	    {
	    	a -= b; 
		}
		
		printf("%d �� %d = ", a, b);
		scanf("%d", &chu);
		if(chu == a / b)
		{
			system("color 07"); //��ΪĬ�� 
			printf("�ش���ȷ!!!!\n");
			t++;
		}
		else
		{
			system("color 02"); //��ɫ 
			printf("�ش�������ٽ�������\n");
			f++;
		}
	}
	system("color 07"); //�ָ�Ĭ�� 
	system("cls");
	int tempGarde = t * 10;
	totalGrade += tempGarde; 
	T += t;
	F += f;
	printf("��ôε÷�Ϊ:%d\n", tempGarde);
	printf("���ܵ÷�Ϊ:%d\n", totalGrade);
}



int main()
{
	srand(time(NULL));
	char c;
	int i;
	char user[10];
	char password[6];
	printf("���������Ϣ����ѧԺ\n");
    printf("20���Ƽ�1��\n");
	printf("�����\n\n");
	printf("�������û�����\n");
	scanf("%s", user);
	printf("���������룺\n");
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
			printf("Сѧ�������������\n");  //�е�Сbugÿ������ѡ���ʱ��Ҫ�������� 
			printf("****A�ӷ�****\n");
			printf("****B����****\n");
			printf("****C�˷�****\n");
			printf("****D����****\n");
			printf("****E�˳�****\n");
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
					printf("�㱾�������Ե���������Ϊ��%d\n", T);
					printf("�㱾�����������������Ϊ��%d\n", F);
					printf("�����������");
					getch();
	 		        return 0;
				} 
				break;
				
				default:printf("����ѡ:");
				system("cls");
			}
		}
	} 
	else
	{
		printf("�û������������!\n");
	} 
	getch(); //����������� 
	return 0; 
}
