#include<stdio.h>

//1.
int maxProfit(int* prices, int pricesSize)
{
    int minprice=0x7fffffff;//(INT_MAX)��¼��ʷ��͵ļ۸�
    int maxret=0;
    for(int i=0;i<pricesSize;i++)
    {
        if(prices[i]<minprice)
        {
            minprice=prices[i];
        }
        else
        {
            //���������ʷ��͵ļ۸��ж�������������Ļ������ǲ������ģ�
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
//        if(prices[i]>max) //��Ʊ�۸�������
//        {
//            max=prices[i];
//            ret=fmax(max-min,ret);
//        }
//        else if(prices[i]<min)//��ͼ۸��½���(ע����else if ���� else)
//        {
//            min=max=prices[i];//���ֵ���������Сֵ�ĺ���
//        }
//    }
//    return ret;
//} 

int main()
{
	int arr[]={7,1,5,3,6,4};
	printf("%d ",maxProfit(arr,6));
 } 
