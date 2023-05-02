#include<stdio.h>

//1.
int maxProfit(int* prices, int pricesSize)
{
    int minprice=0x7fffffff;//(INT_MAX)记录历史最低的价格。
    int maxret=0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]<minprice)
        {
            minprice=prices[i];
        }
        else
        {
            //如果不是历史最低的价格，判断如果今天卖掉的获利，是不是最大的？
            int temp=prices[i]-minprice;
            maxret = temp > maxret ? temp : maxret;
        }
    }
    return maxret;
}


////2.
//int maxProfit(int* prices, int pricesSize)
//{
//    if(pricesSize==0) return 0;
//    int ret=0;
//    int min=prices[0],max=prices[0];
//
//    for(int i=1;i<pricesSize;i++)
//    {
//        if(prices[i]>max) //股票价格上升了
//        {
//            max=prices[i];
//            ret=fmax(max-min,ret);
//        }
//        else if(prices[i]<min)//最低价格下降了(注意是else if 不是 else)
//        {
//            min=max=prices[i];//最大值必须出现最小值的后面
//        }
//    }
//    return ret;
//} 

int main()
{
	int arr[]={7,1,5,3,6,4};
	printf("%d ",maxProfit(arr,6));
 } 
