#include<stdio.h>
#include<math.h>
#include<stdlib.h> 

////枚举(效率低)
//int countPrimes(int n)
//{
//	int count=0;
//	for(int i=2;i<n;i++)
//	{
//		int j=0;
//		for(j=2;j<sqrt(i);j++)
//		{
//			if(i%j==0)
//			{
//				break;
//			}
//		}
//		if(j>sqrt(i))
//		{
//			//printf("%d ",i);
//			count++;
//		}
//	}
//	return count;
//}


//埃氏筛
//如果 x是质数，那么大于 x 的 x 的倍数 2x,3x,...一定不是质数
//我们设map[i]表示数 i 是不是质数，如果是质数则为 1,否则为 0。
//从小到大遍历每个数，如果这个数为质数，则将其所有的倍数都标记为合数（除了该质数本身），即 0。 
//这样在运行结束的时候我们即能知道质数的个数。
int countPrimes(int n)
{
    unsigned char *map =(unsigned char *)calloc(n, sizeof(unsigned char));
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (map[i] == 0)
        {
            for (int j = i * i; j < n; j += i)
            {   // 把 i 的整数倍都标记排除
                map[j] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++)
    {
        if (map[i] == 0)
        {
        	//printf("%d ",i);
            count++;
        }
    }
    return count;
}


int main()
{
    int ret=countPrimes(10);
    printf("\n%d",ret);
}







    

