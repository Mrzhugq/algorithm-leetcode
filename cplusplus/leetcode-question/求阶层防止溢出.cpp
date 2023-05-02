//会溢出 
int uniquePaths(int m, int n) 
{
	int numerator = 1, denominator = 1;
    int count = m - 1;
	int t = m + n - 2;
	while (count--) 
	numerator =numerator * (t--); // 计算分子
	for (int i = 1; i <= m - 1; i++) 
	denominator =denominator * i; // 计算分母 
	
	return numerator / denominator;
}

//不会溢出，边计算分子边除 
int uniquePaths(int m, int n) 
{
	long long numerator = 1; // 分子 
	int denominator = m - 1; // 分母 
	int count = m - 1;
	int t = m + n - 2;
	while(count--)
	{
		numerator=numerator*(t--);
		while(denominator!=0 && numerator%denominator==0)
		{
			numerator/= denominator; 
			denominator--; 
		}
	}
	return numerator;
}

//C count t
