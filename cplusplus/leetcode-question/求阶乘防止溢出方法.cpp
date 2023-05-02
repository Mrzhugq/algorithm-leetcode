#include<stdio.h>
#include<stdlib.h>
#include<math.h>


//   n!/(n-m)!中必定有重复的先约去  ->  (n-m+1 ~ n)连乘  = s
//   s/m! 这里面也有可约分的项，我们边算s边约分 
long long Group1(int n,int m)
{
	long long s=1;
	int k=1;
	
	for(int i=n-m+1; i<=n; i++)
	{
		s*=(long long)i;
		while(k <= m && s%k==0)
		{
			s/=(long long)k;
			k++;
		}
	}
	return s;
}


//s/m!   可以用对数来减少溢出  ->  log(s)-log(m!)
double Group2(int n,int m)
{
	int i;
	double s1=0.0,s2=0.0;
	for(int i=1; i<=m; i++)
	{
		s1+=log(i);
	}
	for(int i=n-m+1; i<=n; i++)
	{
		s2+=log(i);
	}
	return exp(s2-s1);
}


int main()
{
	int n=0,m=0;
	scanf("%d%d",&n,&m);
	if(m > n/2)
	{
		m=n-m;
	}
    printf("%lld\n",Group1(n,m));
	printf("%lf\n",Group2(n,m));
}