#include<stdio.h>
int main()
{
    printf("99乘法表(异性3)为:\n");
    for(int i=1; i<10; i++)
    {
        for(int k=i; k<9; k++)
        {
            printf("       ");
        }
        for(int j=10-i; j<10; j++)
        {
            printf("%d*%d=%2d ",i,j,i*j);
        }
        printf("\n");
    }
}

//#include<stdio.h>
//int main()
//{
//    printf("99乘法表(异性2)为:\n");
//    for(int i=1; i<10; i++)
//    {
//        for(int j=1; j<=10-i; j++)
//        {
//            printf("%d*%d=%2d ",i,j,i*j);
//        }
//        printf("\n");
//    }
//}


//
////#include<stdio.h>
////int main()
////{
////    printf("99乘法表标准为:\n");
////    for(int i=1; i<10; i++)
////    {
////        for(int j=1; j<=i; j++)
////        {
////            printf("%d*%d=%2d ",i,j,i*j);
////        }
////        printf("\n");
////    }
////}
//
////#include<stdio.h>
//int main()
//{
//    printf("99乘法表方阵为:\n");
//    for(int i=1; i<10; i++)
//    {
//        for(int j=1; j<10; j++)
//        {
//            printf("%d*%d=%2d ",i,j,i*j);
//        }
//        printf("\n");
//    }
//}



