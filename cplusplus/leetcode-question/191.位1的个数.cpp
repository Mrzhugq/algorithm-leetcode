//1.暴力法 
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


//2.按位运算 &  
int hammingWeight(uint32_t n) 
{
    int sum=0;
    while(n!=0)
    {
        n=n&(n-1);
		//6 & 5=4     6=(110)  ->   4=(100) 就是把最低位的1变为0，运算一次就有一个1，直到n=0结束 
        sum++;
    }
    return sum;
} 

