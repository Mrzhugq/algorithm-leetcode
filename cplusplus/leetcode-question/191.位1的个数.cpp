//1.������ 
int hammingWeight(uint32_t n) 
{
    int ret[32]={0};
    int i=0;
    int sum=0;
    while(n!=0)
    {
        ret[i]=n%2;
        n=n/2;
        i++;
    }
    for(int j=0;j<32;j++)
    {
        sum=sum+ret[j];
    }
    return sum;
}


//2.��λ���� &  
int hammingWeight(uint32_t n) 
{
    int sum=0;
    while(n!=0)
    {
        n=n&(n-1);
		//6 & 5=4     6=(110)  ->   4=(100) ���ǰ����λ��1��Ϊ0������һ�ξ���һ��1��ֱ��n=0���� 
        sum++;
    }
    return sum;
} 

