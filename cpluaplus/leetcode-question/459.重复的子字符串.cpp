#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//最后的if判断可以这样理解：
//如果答案是 true 的话，next 表前几位（子字符串）都是 0，
//后边将是一直递增，next（n－1）存放的就是原字符串减去子字符串长度的值 ，
//记为len2，将 len－len2的值记为len1
//len1它就是子字符串的长度，一定是可以被 len 整除的！

//求字符串s的next数组
void Getnext(int *next, char *s, int len)
{
    int j=0;
    next[0]=0;
    for(int i=1; i<len; i++)
    {
        while(j>0 && s[i]!=s[j])
        {
            j=next[j-1];
        }
        if(s[i] == s[j])
        {
            j++;
        }
        next[i]=j;
    }
}

bool repeatedSubstringPattern(char * s)
{
    int len = strlen(s);
    if(len == 0) return false;
    int *next = (int*)malloc(sizeof(int) * len);

    Getnext(next, s, len);

    // next[len-1]!=0 代表s字符串有最长的相等前后缀
    // len % (len - next[len-1]) == 0 
    // 代表（数组长度 - 最长相等前后缀的长度）正好可以被数组的长度整除
    if(next[len-1]!=0 && len % (len - next[len-1]) == 0)
    {
        return true;
    }
    return false;
}

int main()
{
	char *s="abcabcabcabc";
	printf("%d ",repeatedSubstringPattern(s));
}