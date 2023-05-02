#include<stdio.h>
#include<string.h>
#include<stdlib.h>


////1.递归暴力 
//bool checkValidSubString(char *s,int i,int j)
//{
//    if(i>j) return true;//递归结束条件
//    if(s[i]==')')
//    {
//        return false;
//    }
//    else if(s[i]=='*')//把'*'当成空格用的时候 就是s[i+1] -> s[j]
//    {
//        if(checkValidSubString(s,i+1,j))
//        {
//            return true;
//        }
//    }
//
//    //s[i]=='(' 和 s[i]=='*' （把'*'当成'('的情况）
//    for(int k=i+1;k<=j;k++)//从第二个开始找
//    {
//        //( *  ) ( )
//        //(left) right 找第二个开始是')'或者'*'的    （ 此时*代表')' ）
//        //left 和 right 代表的也是合法的则全部合法
//        if(s[k]==')' || s[k]=='*')
//        {
//            if(checkValidSubString(s,i+1,k-1) && checkValidSubString(s,k+1,j))
//            {
//                return true;
//            }
//        }
//    }
//    return false;
//}
//bool checkValidString(char * s)
//{
//    return checkValidSubString(s,0,strlen(s)-1);
//}



//2.递归优化 
bool checkValidSubString(char *s,int i,int j,int **cache)
{
    if(i>j) return true;//递归结束条件

    if(cache[i][j]!=0)//已经算过了情况
    {
        if(cache[i][j]==1)
        return true;
        if(cache[i][j]==-1)
        return false;
    }

    //以下没算过情况
    if(s[i]==')')
    {
        cache[i][j]==-1;
        return false;
    }
    else if(s[i]=='*')//把'*'当成空格用的时候 就是s[i+1] -> s[j]
    {
        if(checkValidSubString(s,i+1,j,cache))
        {
            cache[i][j]==1;
            return true;
        }
    }

    //s[i]=='(' 和 s[i]=='*' （把'*'当成'('的情况）
    for(int k=i+1;k<=j;k++)//从第二个开始找
    {
        //( *  ) ( )
        //(left) right 找第二个开始是')'或者'*'的    （ 此时*代表')' ）
        //left 和 right 代表的也是合法的则全部合法
        if(s[k]==')' || s[k]=='*')
        {
            if(checkValidSubString(s,i+1,k-1,cache) && checkValidSubString(s,k+1,j,cache))
            {
                cache[i][j]==1;
                return true;
            }
        }
    }
    cache[i][j]==-1;
    return false;
}
bool checkValidString(char * s)
{
    int len=strlen(s);
    int **cache=(int **)malloc(sizeof(int *)*len);
    for(int i=0;i<len;i++)
    {
        cache[i]=(int *)calloc(len,sizeof(int));
    }
    //0 ：代表还没算过
    //1 ：代表算过 为true
    //-1：代表算过 为false
    return checkValidSubString(s,0,len-1,cache);
}






int main()
{
	char arr[]="(*))";
	printf("%d ",checkValidString(arr));
} 






