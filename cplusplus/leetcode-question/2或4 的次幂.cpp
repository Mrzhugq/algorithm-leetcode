#include<stdio.h>
#include<stdbool.h>

////1. 2�Ĵ��� 
//bool isPowerOfTwo(int n)
//{
//    return n>0 && (n&(n-1))==0;
//    //n�Ķ����Ʊ�ʾ�н�����1��1
//}


//2. 4�Ĵ��� 
bool isPowerOfFour(int n) 
{
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    //(n & (n - 1)) == 0;    Ҫ��4�ı���������2�ı���
    //(n & 0xaaaaaaaa) == 0; ���������λ��ż��λΪ��1
}

int main()
{
	printf("%d ",isPowerOfFour(16));
} 
