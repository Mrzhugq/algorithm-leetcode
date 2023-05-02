#include<stdio.h>
#include<string.h>

//3.栈思想 
bool checkValidString(char * s)
{
    //s: "((*"  (三种情况)

    //s:"((("  count++
    //s:"(()"  count--
    //s:"(( "  count
    int len=strlen(s);
    //一种括号只需要常数就行了
    int minCount=0;//最少有多少个'('
    int maxCount=0;//最多有多少个'('
    for(int i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            maxCount++;
            minCount++;
        }
        else if(s[i]==')')
        {
            maxCount--;
            minCount--;
        }
        else if(s[i]=='*')
        {
            maxCount++; //'*' 为 '('
            minCount--; //'*' 为 ')'
            //'*' 为 空格都不变
        }

        if(maxCount<0)
        {
            return false;
        }
        if(minCount<0) //当第一个为'*'时只能用作'('  或  空（空可以忽略）
        {
            minCount=0;
        }
    }
    return minCount==0;
}



int main()
{
	char arr[]="(*))";
	printf("%d ",checkValidString(arr));
} 
