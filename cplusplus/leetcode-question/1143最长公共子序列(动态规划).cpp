#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
int DP(char *text1,char *text2,int m,int n,int **cache)
{
    if(m==0 || n==0) return 0;
    if(cache[m][n]!=-1) return cache[m][n];//�������
    int retsult;
    if(text1[m-1]==text2[n-1])
    {
        //������һ����ĸ��ȣ�������� ��ȥ�����һ����ĸ�������������+1
        retsult=DP(text1,text2,m-1,n-1,cache)+1;
    }
    else
    {
        //����ȣ�������� �����ַ����зֱ�ȥ�����һ���ַ�������������е����ֵ
        int temp1=DP(text1,text2,m-1,n,cache);
        int temp2=DP(text1,text2,m,n-1,cache);
        if(temp2>temp1)
        retsult=temp2;
        else
        retsult=temp1;
    }
    cache[m][n]=retsult;
    return retsult;
}

int longestCommonSubsequence(char * text1, char * text2)
{
    int len1=strlen(text1);
    int len2=strlen(text2);

    int** cache=(int**)malloc(sizeof(int*)*(len1+1));
    for(int i=0;i<=len1;i++)
    {
        cache[i]=(int*)malloc(sizeof(int)*(len2+1));
    }
    for(int i=0;i<=len1;i++)//��ʼֵ����Ϊ-1
    {
        for(int j=0;j<=len2;j++)
        {
            cache[i][j]=-1;
        }
    }
    int ret=DP(text1,text2,len1,len2,cache);
    for(int i=0;i<=len1;i++)//�ͷ�
    {
        free(cache[i]);
    }
    free(cache);
    return ret;
}

int main()
{
	char text1[]="abcde";
	char text2[]="ace";
	printf("%d ",longestCommonSubsequence(text1,text2));
	return 0;
} 
