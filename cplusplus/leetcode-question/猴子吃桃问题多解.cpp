#include<stdio.h>
int main()
{
    int i=0;
    int x=1;
    while(i<9)
    {
        x=(x+1)*2;
        i++;
    }
    printf("��һ��ժ��������Ϊ��%d",x);
}


//#include<stdio.h>
//int main()
//{
//    int i=0;
//    int x=1;
//    do
//    {
//        x=(x+1)*2;
//        i++;
//    }while(i<9);
//    printf("��һ��ժ��������Ϊ��%d",x);
//}


//#include<stdio.h>
//int main()
//{
//    int i=0;
//    int x=1;
//    for(i=0; i<9; i++)
//    {
//        x=(x+1)*2;
//    }
//    printf("��һ��ժ��������Ϊ��%d",x);
//}


//#include<stdio.h>
//int total(int day)
//{
//    if(day==10)
//        return 1;
//    else
//        return (total(day+1)+1)*2;
//}
//int main()
//{
//    int x=total(1);
//    printf("��һ��ժ��������Ϊ��%d",x);
//}

