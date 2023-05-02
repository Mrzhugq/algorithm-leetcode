//1.参考上一个代码写的 
int hammingDistance(int x, int y)
{
    int z=(uint32_t)x^y;
    int sum=0;
    while(z!=0)
    {
        z=z&(z-1);
        sum++;
    }
    return sum;
}
