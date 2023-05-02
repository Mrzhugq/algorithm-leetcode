#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// i 指向后缀末尾
// j 指向前缀末尾，还代表i之前包括i 字串最长相等前后缀的长度
void Getnext(int *next, char *s, int len2)
{
    int j=0;
    next[0] = 0;
    for(int i=1; i<len2; i++)
    {
        //前后缀不相同
        while(j>0 && s[i]!=s[j])
        {
            j=next[j-1];
        }

        //前后缀相同
        if(s[i] == s[j])
        {
            j++;
        }
        //更新next数组
        next[i]=j;
    }
}


//例如：haystack = aabaabaaf
//      neddle = aabaaf
int strStr(char * haystack, char * needle)
{
    int len1 = strlen(haystack);
    int len2 = strlen(needle);
    if(len2 == 0) return 0;
    int *next = (int*)malloc(sizeof(int) * len2);

    Getnext(next, needle, len2);

    int j=0; 
    for(int i=0; i<len1; i++)
    {
        while(j>0 && haystack[i]!=needle[j])
        {
            j=next[j-1];
        }
        if(haystack[i] == needle[j])
        {
            j++;
        }
        if(j == len2)
        {
            return i - len2 + 1;
        }
    }
    return -1;
}

int main()
{
	char arr1[]="aabaabaaf";
	char arr2[]="aabaaf";
	printf("%d ",strStr(arr1,arr2));
}
