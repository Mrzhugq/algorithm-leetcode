//����� 
int uniquePaths(int m, int n) 
{
	int numerator = 1, denominator = 1;
    int count = m - 1;
	int t = m + n - 2;
	while (count--) 
	numerator =numerator * (t--); // �������
	for (int i = 1; i <= m - 1; i++) 
	denominator =denominator * i; // �����ĸ 
	
	return numerator / denominator;
}

//����������߼�����ӱ߳� 
int uniquePaths(int m, int n) 
{
	long long numerator = 1; // ���� 
	int denominator = m - 1; // ��ĸ 
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
