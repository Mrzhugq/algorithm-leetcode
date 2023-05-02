#include<stdio.h>
#include<math.h>
#include<stdlib.h> 

////ö��(Ч�ʵ�)
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


//����ɸ
//��� x����������ô���� x �� x �ı��� 2x,3x,...һ����������
//������map[i]��ʾ�� i �ǲ��������������������Ϊ 1,����Ϊ 0��
//��С�������ÿ��������������Ϊ�������������еı��������Ϊ���������˸������������� 0�� 
//���������н�����ʱ�����Ǽ���֪�������ĸ�����
int countPrimes(int n)
{
    unsigned char *map =(unsigned char *)calloc(n, sizeof(unsigned char));
    for (int i = 2; i <=sqrt(n); i++)
    {
        if (map[i] == 0)
        {
            for (int j = i * i; j < n; j += i)
            {   // �� i ��������������ų�
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







    

