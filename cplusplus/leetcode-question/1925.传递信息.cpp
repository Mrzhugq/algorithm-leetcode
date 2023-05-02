//n = 5
//relation = [[0,2],[2,1],[3,4],[2,3],[1,4],[2,0],[0,4]]
//k = 3


//这题也可以用动态规划，DFS，BFS（邻接矩阵）做 


int Find(int n, int** relation, int relationSize, int k)
{
    int count=0; //这句秒啊，画展开图能理解
    if(k==1) 
    {
        for(int i=0; i<relationSize; i++)
        {
            if(relation[i][1]==n-1 && relation[i][0]==0)
            {
                return 1;
            }
        }
        return 0;
    }
    
    for(int i=0; i<relationSize; i++)
    {
        if(relation[i][1] == n-1) 
        {
            count+=Find(relation[i][0]+1, relation, relationSize, k-1);
        }
    }
    return count;
}

int numWays(int n, int** relation, int relationSize, int* relationColSize, int k)
{
    int Sum=Find(n, relation, relationSize, k);
    return Sum;
}
