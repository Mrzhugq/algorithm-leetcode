#include<stdio.h>
//1. 
int rangeBitwiseAnd(int left, int right)
{
    //left        : 00110101|0010101001
    //right       : 00110101|1010100010
    //-----------------------------------
    //left        : 0000000000|00110101
    //right       : 0000000000|00110101
    //----------------------------------
    //left<<count : 00110101|0000000000

    int count = 0;
    while(left != right)//先把右边不一样的部分舍去，同时记录舍去的位数
    {
        left=left>>1;
        right=right>>1;
        count++;
    }
    //结束循环时left=right，最后把left或right左翼count位就是答案
    return left<<count; //return right<<count;
}


////2.
//int rangeBitwiseAnd(int left, int right)
//{
//    int ret=0;
//    bool isDifferent=false;
//    for(int i=30;i>=0;i--)
//    {
//        int dleft = left & (1<<i);
//        int dright = right & (1<<i);
//        if(dleft != dright)
//        {
//            isDifferent=true;
//            break;
//        }
//        if(isDifferent != true)
//        {
//            ret=ret+dleft; //ret=ret+dright;
//        }
//    }
//    return ret;
//} 

int main()
{
	printf("%d ",rangeBitwiseAnd(5,7));
} 
