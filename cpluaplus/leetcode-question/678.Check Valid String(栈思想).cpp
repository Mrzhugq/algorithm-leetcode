#include<stdio.h>
#include<string.h>

//3.ջ˼�� 
bool checkValidString(char * s)
{
    //s: "((*"  (�������)

    //s:"((("  count++
    //s:"(()"  count--
    //s:"(( "  count
    int len=strlen(s);
    //һ������ֻ��Ҫ����������
    int minCount=0;//�����ж��ٸ�'('
    int maxCount=0;//����ж��ٸ�'('
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
            maxCount++; //'*' Ϊ '('
            minCount--; //'*' Ϊ ')'
            //'*' Ϊ �ո񶼲���
        }

        if(maxCount<0)
        {
            return false;
        }
        if(minCount<0) //����һ��Ϊ'*'ʱֻ������'('  ��  �գ��տ��Ժ��ԣ�
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
