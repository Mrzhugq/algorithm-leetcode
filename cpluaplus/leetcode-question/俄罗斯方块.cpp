#include<stdio.h>
#include<time.h>
#include<Windows.h>
#define HEIGHT  28  //��ͼ�߶�
#define WIDTH   20  //��ͼ���
#define ZERO    1
#define HEIGHT_1 18
#define Loca_y    6
#define Loca_x    25
#define PRINTF  printf("��");
#define LINE    printf("\n");
#define EMPTY   printf("  ");
typedef struct Tetris
{
 int x_1, y_1;   //��x���꣬��y���꣬��������Ϊ������ͨ��������ȷ����������
 int x_2, y_2;
 int x_3, y_3;
 int x_4, y_4;
 int code;//7�ַ�����̬����
 Tetris * next;
}Tetris;
void DeawMap();                     	//���Ƶ�ͼ 
Tetris * BlockRand(int code);    	 	//�������������  
void JudgeDirection(Tetris ** Block); //������Ӧ 
void Form(Tetris ** Block);      		//��������ȫ��ȷ��
void ShowBlock(Tetris ** Block);    	//��ʾ�������� 
int JudgeWall(Tetris ** Block);     	//�ж����ҽ���
void MoveCursor(int x, int y);      	//�ƶ����  ����������Ϊÿ�β���ˢ��ȫ����ͼ��ֻ��ˢ��ĳһ�ض�����
void SetColour(int c);              	//��ɫ�趨
int JudgeGroud(Tetris * Phead, Tetris ** Block);//�ж����
void JudgeEntire(Tetris * Head);    	//�ж������Ƿ�����
void NewEntire(Tetris * head, int y);  //�����溯����������������У���ˢ�µ�ͼ
void Show(int n);        			//��ʾ��Ϣ����һ������÷��������������һЩ��Ϣ�����ڸú������޸�
void Location(Tetris ** Block, int x, int y, int a, int b, int c, int d, int e, int f);   //�������1
void Location_y(Tetris ** Block, int x, int y, int a, int b, int c, int d, int e, int f); //�������2
void Location_x(int x, int y, int a, int b, int c, int d, int e, int f);                  //��Ϣ����
Tetris *Phead = NULL;   //����ͷָ��
Tetris *Pend = NULL;    //����ָ�� ��β�巨��Ҫ��
Tetris * Return = NULL; //�ڵ��ַ����
int form = 0; //�ж���̬
int UP = 0;   //�½��ٶ��ж�
int code_y = 0;//�����̬
int fengs = 0; //�÷�

int main()
{
 DeawMap();
 code_y = rand() % 7 + 1;
 while (1)
 {
  Return = BlockRand(code_y);
  code_y = rand() % 7 + 1;
  Show(code_y);
  ShowBlock(&Return);
 }
 system("pause>nul");
 return 0;
}

void DeawMap()
{
 for (int i = 0; i < WIDTH; i++)PRINTF LINE  //�ϱ߿�
  for (int i = 1; i < HEIGHT - 1; i++)          //��ӡ���ұ߿�
  {
   for (int j = 0; j < WIDTH; j++)
   {
    if (j == 0 || j == WIDTH - 1)
    {
     PRINTF
      if (j == WIDTH - 1)LINE
    }
    else EMPTY
   }
  }
 for (int i = 0; i < WIDTH; i++)PRINTF LINE  //�±߿�
 system("color 03");
}

void Location(Tetris ** Block, int x, int y, int a, int b, int c, int d, int e, int f)
{
 (*Block)->x_1 = (*Block)->x_1 + x;
 (*Block)->y_1 = (*Block)->y_1 + y;
 (*Block)->x_2 = (*Block)->x_1 + a;
 (*Block)->y_2 = (*Block)->y_1 + b;
 (*Block)->x_3 = (*Block)->x_1 + c;
 (*Block)->y_3 = (*Block)->y_1 + d;
 (*Block)->x_4 = (*Block)->x_1 + e;
 (*Block)->y_4 = (*Block)->y_1 + f;
}

void Location_y(Tetris ** Block, int x, int y, int a, int b, int c, int d, int e, int f)
{
 (*Block)->x_1 = (*Block)->x_1 + x;
 (*Block)->y_1 = (*Block)->y_1 + y;
 (*Block)->x_2 = (*Block)->x_2 + a;
 (*Block)->y_2 = (*Block)->y_2 + b;
 (*Block)->x_3 = (*Block)->x_3 + c;
 (*Block)->y_3 = (*Block)->y_3 + d;
 (*Block)->x_4 = (*Block)->x_4 + e;
 (*Block)->y_4 = (*Block)->y_4 + f;
}

Tetris * BlockRand(int code_y)
{
 srand((int)time(0));
 Tetris * Block = (Tetris*)malloc(sizeof(Tetris));
 Block->x_1 = 8;
 Block->y_1 = 4;//�涨��ʼ���ķ��������Ϊ(8,4)
 Block->code = code_y;
 if (Phead == NULL)Phead = Block;
 else Pend->next = Block;
 Block->next = NULL;
 Pend = Block;
 return Block;
}

void ShowBlock(Tetris ** Block)
{
 while (1)
 {

  Form(&Return); 
  if ((*Block)->code == 1)SetColour(13);
  if ((*Block)->code == 2)SetColour(15);
  if ((*Block)->code == 3)SetColour(12);
  if ((*Block)->code == 4)SetColour(10);
  if ((*Block)->code == 5)SetColour(6);
  if ((*Block)->code == 6)SetColour(4);
  if ((*Block)->code == 7)SetColour(8);
  MoveCursor((*Block)->x_1, (*Block)->y_1); PRINTF
  MoveCursor((*Block)->x_2, (*Block)->y_2); PRINTF
  MoveCursor((*Block)->x_3, (*Block)->y_3); PRINTF
  MoveCursor((*Block)->x_4, (*Block)->y_4); PRINTF
  if (JudgeGroud(Phead, &Return) == 0)
  {
   system("color 03");
   break;
  }
  if (UP == 0)
  {
   for (int i = 0; i <= 400000000; i++) {}
  }
  if (UP == 1)
  {
   for (int i = 0; i <= 40000000; i++) {}
   UP = 0;
  }
  MoveCursor((*Block)->x_1, (*Block)->y_1); EMPTY
  MoveCursor((*Block)->x_2, (*Block)->y_2); EMPTY
  MoveCursor((*Block)->x_3, (*Block)->y_3); EMPTY
  MoveCursor((*Block)->x_4, (*Block)->y_4); EMPTY
  Location_y(&Return, 0, 1, 0, 1, 0, 1, 0, 1);
  JudgeDirection(&Return);
  JudgeEntire(Phead);
 }
}

void JudgeDirection(Tetris ** Block)
{
 if (GetAsyncKeyState(VK_UP) && 0x8000)
 {
  form += 1;
  if (form == 4)
  {
   form = 0;
  }
  Form(&Return);
 }
 if (GetAsyncKeyState(VK_DOWN) && 0x8000)
 {
  //��������  ʱ�����
  UP = 1;
 }
 if (GetAsyncKeyState(VK_LEFT) && 0x8000)
 {
  //�����ƶ�
  if (JudgeWall(&Return) != -1) Location_y(&Return, -1, 0, -1, 0, -1, 0, -1, 0);
 }
 if (GetAsyncKeyState(VK_RIGHT) && 0x8000)
 {
  //�����ƶ�
  if (JudgeWall(&Return) != -2) Location_y(&Return, 1, 0, 1, 0, 1, 0, 1, 0);
 }
 if (GetAsyncKeyState(VK_ESCAPE) && 0x0D)
 {
  MoveCursor(27, 15);
  printf("��Ϸ��ͣ");
  //�ж�Esc
  while (1)
  {
   if (GetAsyncKeyState(VK_ESCAPE) && 0x0D)
   {
    MoveCursor(27, 15);
    printf("       ");
    break;
   }
  }
 }
}

void Form(Tetris ** Block)
{
 //��ȷʵ��һ�࣬��ϸ��
 switch ((*Block)->code)
 {
 case 1:
  if (form == 0)Location(&Return, 0, 0, -1, 0, 0, -1, 1, 0);
  if (form == 1)Location(&Return, 0, 0, 0, 1, 0, -1, 1, 0);
  if (form == 2)Location(&Return, 0, 0, 0, 1, -1, 0, 1, 0);
  if (form == 3)Location(&Return, 0, 0, 0, 1, -1, 0, 0, -1);
  break;
 case 2:
  Location(&Return, 0, 0, 1, 0, 0, 1, 1, 1);
  break;
 case 3:
  if (form == 0 || form == 2)Location(&Return, 0, 0, 0, -1, 0, 1, 0, 2);
  if (form == 1 || form == 3)Location(&Return, 0, 0, -1, 0, 1, 0, 2, 0);
  break;
 case 4:
  if (form == 0)Location(&Return, 0, 0, -1, 0, 1, 0, 1, -1);
  if (form == 1)Location(&Return, 0, 0, 0, -1, 1, 0, 0, -2);
  if (form == 2)Location(&Return, 0, 0, 0, -1, 1, -1, 2, -1);
  if (form == 3)Location(&Return, 0, 0, 0, -1, 0, -2, -1, -2);
  break;
 case 5:
  if (form == 0)Location(&Return, 0, 0, 1, 0, 2, 0, 0, -1);
  if (form == 1)Location(&Return, 0, 0, 1, 0, 1, -1, 1, -2);
  if (form == 2)Location(&Return, 0, 0, 1, 0, 2, 0, 2, 1);
  if (form == 3)Location(&Return, 0, 0, 1, 0, 0, 1, 0, 2);
  break;
 case 6:
  if (form == 0 || form == 2)Location(&Return, 0, 0, 0, -1, 1, 0, 1, 1);
  if (form == 1 || form == 3)Location(&Return, 0, 0, 0, -1, 1, -1, -1, 0);
  break;
 case 7:
  if (form == 0 || form == 2)Location(&Return, 0, 0, 0, 1, 1, 0, 1, -1);
  if (form == 1 || form == 3)Location(&Return, 0, 0, 0, 1, -1, 0, 1, 1);
 }
}

void MoveCursor(int x, int y)//���ù��λ��(���������ʾ�Ŀ�ʼλ��)
{
 COORD pos = { x * 2,y };
 HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//��� ��׼����ľ��   
 SetConsoleCursorPosition(output, pos); //���ÿ���̨���λ��
}

void SetColour(int c)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//API�������Ըı����̨��ɫ
}
int JudgeWall(Tetris ** Block)
{
 if ((*Block)->x_1 == ZERO || (*Block)->x_2 == ZERO || (*Block)->x_3 == ZERO || (*Block)->x_4 == ZERO)return -1;
 if ((*Block)->x_1 == HEIGHT_1 || (*Block)->x_2 == HEIGHT_1 || (*Block)->x_3 == HEIGHT_1 || (*Block)->x_4 == HEIGHT_1)return -2;
 return 0;
}

int JudgeGroud(Tetris * Phead, Tetris ** Block)
{
 
 Tetris * P = Phead;
 //���������Ͳ㡣ֱ�Ӿ�����һѭ��
 if ((*Block)->y_1 == 26 || (*Block)->y_2 == 26 || (*Block)->y_3 == 26 || (*Block)->y_4 == 26)return 0;
 while (P->next != NULL)
 {
  if (P->y_1 == (*Block)->y_1 + 1)
  {
   if (P->x_1 == (*Block)->x_1)return 0;
  }
  if (P->y_2 == (*Block)->y_1 + 1)
  {
   if (P->x_2 == (*Block)->x_1)return 0;
  }
  if (P->y_3 == (*Block)->y_1 + 1)
  {
   if (P->x_3 == (*Block)->x_1)return 0;
  }
  if (P->y_4 == (*Block)->y_1 + 1)
  {
   if (P->x_4 == (*Block)->x_1)return 0;
  }
  if (P->y_1 == (*Block)->y_2 + 1)
  {
   if (P->x_1 == (*Block)->x_2)return 0;
  }
  if (P->y_2 == (*Block)->y_2 + 1)
  {
   if (P->x_2 == (*Block)->x_2)return 0;
  }
  if (P->y_3 == (*Block)->y_2 + 1)
  {
   if (P->x_3 == (*Block)->x_2)return 0;
  }
  if (P->y_4 == (*Block)->y_2 + 1)
  {
   if (P->x_4 == (*Block)->x_2)return 0;
  }
  if (P->y_1 == (*Block)->y_3 + 1)
  {
   if (P->x_1 == (*Block)->x_3)return 0;
  }
  if (P->y_2 == (*Block)->y_3 + 1)
  {
   if (P->x_2 == (*Block)->x_3)return 0;
  }
  if (P->y_3 == (*Block)->y_3 + 1)
  {
   if (P->x_3 == (*Block)->x_3)return 0;
  }
  if (P->y_4 == (*Block)->y_3 + 1)
  {
   if (P->x_4 == (*Block)->x_3)return 0;
  }
  if (P->y_1 == (*Block)->y_4 + 1)
  {
   if (P->x_1 == (*Block)->x_4)return 0;
  }
  if (P->y_2 == (*Block)->y_4 + 1)
  {
   if (P->x_2 == (*Block)->x_4)return 0;
  }
  if (P->y_3 == (*Block)->y_4 + 1)
  {
   if (P->x_3 == (*Block)->x_4)return 0;
  }
  if (P->y_4 == (*Block)->y_4 + 1)
  {
   if (P->x_4 == (*Block)->x_4)return 0;
  }
  P = P->next;
 }
 return 1;
}

void JudgeEntire(Tetris * Head)
{
 Tetris * PHead = Head;
 //��1��26
 for (int y = 26; y >= 1; y--)
 {
  int sum = 0;
  while (PHead->next != NULL)
  {
   if (PHead->y_1 == y)sum++;
   if (PHead->y_2 == y)sum++;
   if (PHead->y_3 == y)sum++;
   if (PHead->y_4 == y)sum++;
   MoveCursor(20, 28);
   PHead = PHead->next;
  }
  PHead = Head;
  if (sum == 18)
  {
   NewEntire(Phead, y);
   fengs += 10;
   Show(code_y);
  }
  sum = 0;
 }
}

void NewEntire(Tetris * head,int y)
{
 Tetris * PHead = head;
 while (PHead->next != NULL)
 {
  if (PHead->y_1 == y)
  {
   MoveCursor(PHead->x_1, PHead->y_1); EMPTY
   PHead->x_1 = 99;
   PHead->y_1 = 99;
  }
  if (PHead->y_2 == y)
  {
   MoveCursor(PHead->x_2, PHead->y_2); EMPTY
   PHead->x_2 = 99;
   PHead->y_2 = 99;
  }
  if (PHead->y_3 == y)
  {
   MoveCursor(PHead->x_3, PHead->y_3); EMPTY
   PHead->x_3 = 99;
   PHead->y_3 = 99;
  }
  if (PHead->y_4 == y)
  {
   MoveCursor(PHead->x_4, PHead->y_4); EMPTY
   PHead->x_4 = 99;
   PHead->y_4 = 99;
  }
  PHead = PHead->next;
 }
 PHead = head;
 while (PHead->next != NULL)
 {
  if (PHead->y_1 < y)
  {
   MoveCursor(PHead->x_1, PHead->y_1); EMPTY
   PHead->y_1 += 1;
   MoveCursor(PHead->x_1, PHead->y_1); PRINTF
  }
  if (PHead->y_2 < y)
  {
   MoveCursor(PHead->x_2, PHead->y_2); EMPTY
   PHead->y_2 += 1;
   MoveCursor(PHead->x_2, PHead->y_2); PRINTF
  }
  if (PHead->y_3 < y)
  {
   MoveCursor(PHead->x_3, PHead->y_3); EMPTY
   PHead->y_3 += 1;
   MoveCursor(PHead->x_3, PHead->y_3); PRINTF
  }
  if (PHead->y_4 < y)
  {
   MoveCursor(PHead->x_4, PHead->y_4); EMPTY
   PHead->y_4 += 1;
   MoveCursor(PHead->x_4, PHead->y_4); PRINTF
  }
  PHead = PHead->next;
 }
}

void Show(int n)
{
 //��ʾ��һ������
 //����ո�����
 for (int j = 4; j <= 8; j++)
 {
  for (int i = 23; i <= 28; i++)
  {
   MoveCursor(i, j);  EMPTY
  }
 }
 MoveCursor(24, 3); 
 printf("��һ���������ࣺ");
 MoveCursor(24, 10);
 printf("��Ϸ�÷֣�%d", fengs);
 MoveCursor(24, 12);
 if (n == 1)
 {
  SetColour(13);
  Location_x(-1, 0, 0, 0, 1, 0, -1, -1);
 }
 if (n == 2)
 {
  SetColour(15);
  Location_x(0, 0, 1, 0, -1, 1, 1, 1);
 }
 if (n == 3)
 {
  SetColour(12);
  Location_x(0, 0, 1, 0, 2, 0, 3, 0);
 }
 if (n == 4)
 {
  SetColour(10);
  Location_x(0, 0, 1, 0, 2, 0, 2, -1);
 }
 if (n == 5)
 {
  SetColour(6);
  Location_x(0, -1, 0, 0, 1, 0, 2, 0);
 }
 if (n == 6)
 {
  SetColour(4);
  Location_x(-1, -1, -1, 0, 0, 0, 0, 1);
 }
 if (n == 7)
 {
  SetColour(8);
  Location_x(0, -1, 0, 0, -1, 0, -1, 1);
 }
}

void Location_x(int x, int y, int a, int b, int c, int d, int e, int f)
{
     MoveCursor(Loca_x+x, Loca_y+y); PRINTF
  MoveCursor(Loca_x+a, Loca_y+b); PRINTF
  MoveCursor(Loca_x+c, Loca_y+d); PRINTF
  MoveCursor(Loca_x+e, Loca_y+f); PRINTF
}

