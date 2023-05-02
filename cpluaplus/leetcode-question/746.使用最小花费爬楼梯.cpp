int minCostClimbingStairs(int* cost, int costSize)
{
    int* dp=malloc(sizeof(int)*(costSize));
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<costSize;i++)
    {
        dp[i]=fmin(dp[i-1],dp[i-2])+cost[i];
    }
    //最后一步不用花费，所以取倒数第?步，第?步的最少值
    return fmin(dp[costSize-1],dp[costSize-2]);
}
