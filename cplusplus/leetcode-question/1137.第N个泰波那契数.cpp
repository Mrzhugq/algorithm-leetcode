class Solution 
{
public:
    int tribonacci(int n) 
    {
        int f0 = 0;
        int f1 = 1;
        int f2 = 1;
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        for(int i=3; i<=n; i++)
        {
            int temp = f2;
            f2 = f0 + f1 + f2;
            f0 = f1;
            f1 = temp;
        }
        return f2;
    }
};
