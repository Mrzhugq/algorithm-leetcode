#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* replaceSpace(char* s)
{
    int len=strlen(s);
    char *ret=(char*)malloc(sizeof(char)*(3*len+1));
    int j=0;
    for(int i=0; i<len; i++)
    {
        if(s[i]!=' ')
        {
            ret[j++]=s[i];
        }
        else
        {
            ret[j++]='%';
            ret[j++]='2';
            ret[j++]='0';
        }
    }
    ret[j]='\0';
    return ret;
}
