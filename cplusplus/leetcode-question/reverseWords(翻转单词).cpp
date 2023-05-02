#include<stdio.h>
#include<string.h>
#include<stdlib.h> 

char *reverseWords(char *s)
{
	while(*s==' ') s++;
	int len=strlen(s)-1;
	if(len<0) return s;
	while(s[len]==' ')
	{
		s[len]=='\0';
		len--;
	}
	//strtok也可以不用去除字符串前后空格 
	char **stack=(char **)malloc(sizeof(char*) * (len+2)/2);
	char *temp;
	int top=0;
	
	for(char *token=strtok(s," ") ; token!=NULL ; token=strtok(NULL," "))
	{
		temp=(char *)malloc(sizeof(char) * (len+2));
		strcpy(temp,token);
		stack[top++]=temp;
	}
	int word_len=0;
	while(top)
	{
		temp=stack[--top];
		strcpy(s+word_len,temp);
		word_len=word_len+strlen(temp);
		free(temp);
		s[word_len++]=' ';
	} 
	free(stack);
	s[word_len-1]='\0';
	return s;
}
int main()
{
	char s[]="  i   am   zhuguoqing ";
	char *ret=reverseWords(s);
	printf("%s\n",ret);
	return 0;
}
