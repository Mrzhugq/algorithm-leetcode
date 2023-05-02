#include<stdio.h>
#include<stdbool.h>

////1. 2的次幂 
//bool isPowerOfTwo(int n)
//{
//    return n>0 && (n&(n-1))==0;
//    //n的二进制表示中仅包含1个1
//}


//2. 4的次幂 
bool isPowerOfFour(int n) 
{
    return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
    //(n & (n - 1)) == 0;    要是4的倍数必须是2的倍数
    //(n & 0xaaaaaaaa) == 0; 必须二进制位的偶数位为是1
}

int main()
{
	printf("%d ",isPowerOfFour(16));
} 
