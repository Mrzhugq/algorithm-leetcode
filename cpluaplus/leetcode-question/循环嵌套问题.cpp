#include<stdio.h>
int main()
{
    printf("99�˷���(����3)Ϊ:\n");
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
//    printf("99�˷���(����2)Ϊ:\n");
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
////    printf("99�˷����׼Ϊ:\n");
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
//    printf("99�˷�����Ϊ:\n");
//    for(int i=1; i<10; i++)
//    {
//        for(int j=1; j<10; j++)
//        {
//            printf("%d*%d=%2d ",i,j,i*j);
//        }
//        printf("\n");
//    }
//}



