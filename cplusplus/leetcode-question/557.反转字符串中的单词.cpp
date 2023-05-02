#include<stdio.h>
#include<string.h>
 
void reverse(char* s, int left, int right)
{
    while(left < right)
    {
        int temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

char * reverseWords(char * s)
{
    int len = strlen(s);
    int end = 0;
    while(end < len)
    {
        int start = end;
        while(end<len && s[end]!=' ')
        {
            end++;
        }
        reverse(s, start, end-1);
        end++;//Ìø¹ý¿Õ¸ñ
    }
    return s;
}

int main()
{
	char s[] = "Let's take LeetCode contest";
	reverseWords(s);
	puts(s);
	return 0;
}

