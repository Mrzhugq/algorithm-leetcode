#include<stdio.h>
#include<string.h> 
char pairs(char a) 
{
    if (a == ')') 
    {
        return '(';
    } 
    else if (a == '}') 
    {
        return '{';
    } 
    else if (a == ']') 
    {
        return '[';
    }
    return 0;
}
bool isValid(char * s)
{
	int len=strlen(s);
	
	if(len%2==1)
	return false;
	
	int stack[len+1];
	int top=0;
	for(int i=0;i<len;i++)
	{
		char ch=pairs(s[i]);
		if(ch==0)
		{
			//��ջ
			stack[top]=s[i];
			top++;
		}
		else
		{
			if(top==0 || stack[top-1]!=ch)
			{
				return false;
			}
			top--;     //stack[top-1]=ch ��ջ 
		}
	}
	return top==0;    //���ѭ������ջ���滹�����ţ��򷵻�false�����û������true
} 

int main() 
{
	char arr[]="(){}[]";
	int ret=isValid(arr);
	printf("%d ",ret);
 } 
