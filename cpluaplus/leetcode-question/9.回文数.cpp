#include<stdio.h> 
//1.
bool isPalindrome(int x)
{
    //��ת����x
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
//    //��ת�����x
//    if(x<0 || (x%10==0 && x!=0))  return false;
//    int reverse=0;
//    while(x > reverse)
//    {
//        reverse=reverse*10+x%10;
//        x=x/10;
//    }
//    //x==(reverse/10) -> ���xΪ����12321,ѭ������x=12 reverse=123,x��reverse/10�ж��Ƿ���Ⱦ�����  
//    return x==reverse || x==(reverse/10);
//}


int main()
{
	printf("%d ",isPalindrome(1221));
} 
