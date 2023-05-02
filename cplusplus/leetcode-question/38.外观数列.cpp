#include<stdio.h>
#include<stdlib.h> 
#include<string.h>

char * countAndSay(int n)
{
    char *temp=(char*)malloc(sizeof(char)*5000);
    char *ret=(char*)malloc(sizeof(char)*5000);
    char *p;
    int i=1;
    ret[0]='1';
    ret[1]='\0';
    while(i<n)
    {
        p=ret;
        int j=0;
        while(*p!='\0')
        {
            int count=1;
            char key=*p;
            while(key == *(++p))
            {
                count++;
            }
            temp[j]=count+'0'; //×ª»¯Îª×Ö·û¡®count¡¯
            j++;
            temp[j]=key;
            j++;
        }
        temp[j]='\0';
        strcpy(ret,temp);
        i++;
    }
    return ret;
}

int main()
{
	char *ret=countAndSay(4);
	puts(ret);
}
