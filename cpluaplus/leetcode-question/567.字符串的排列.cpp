#include<stdio.h>
#include<string.h>

bool IsEqual(int *arr1, int*arr2)
{
    for(int i=0; i<26; i++)
    {
        if(arr1[i] != arr2[i])
        return false;
    }
    return true;
}


bool checkInclusion(char * s1, char * s2)
{
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int cnt1[26] = {0}, cnt2[26] = {0}; 
    if(len1 > len2)
    {
        return false;
    }
    
    for(int i=0; i<len1; i++)
    {
        cnt1[s1[i] - 'a']++;
        cnt2[s2[i] - 'a']++;
    }
    if(IsEqual(cnt1, cnt2))
    {
        return true;
    }
    for(int i=len1; i<len2; i++)//固定长度为len1的滑动窗口
    {
        cnt2[s2[i] - 'a']++;
        cnt2[s2[i-len1] - 'a']--;
        if(IsEqual(cnt1, cnt2))
        {
            return true;
        }
    }
    return false;
}


int main()
{
	char ch1[] = "ab";
	char ch2[] = "eidbaooo";
	bool ret = checkInclusion(ch1, ch2);
	printf("%d ",ret);
	return 0;
}

