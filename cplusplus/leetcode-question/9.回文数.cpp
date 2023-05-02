#include<stdio.h> 
//1.
bool isPalindrome(int x)
{
    //反转整个x
    if(x<0)  return false;
    int temp=x;
    long long n=0;
    while(temp!=0)
    {
        n=n*10+temp%10;
        temp/=10;
    } 
    return n==x?true:false;
}



////2. 
//bool isPalindrome(int x)
//{
//    //反转半个个x
//    if(x<0 || (x%10==0 && x!=0))  return false;
//    int reverse=0;
//    while(x > reverse)
//    {
//        reverse=reverse*10+x%10;
//        x=x/10;
//    }
//    //x==(reverse/10) -> 如果x为奇数12321,循环结束x=12 reverse=123,x与reverse/10判断是否相等就行了  
//    return x==reverse || x==(reverse/10);
//}


int main()
{
	printf("%d ",isPalindrome(1221));
} 
