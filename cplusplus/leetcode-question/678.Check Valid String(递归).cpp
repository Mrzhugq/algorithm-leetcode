#include<stdio.h>
#include<string.h>
#include<stdlib.h>


////1.�ݹ鱩�� 
//bool checkValidSubString(char *s,int i,int j)
//{
//    if(i>j) return true;//�ݹ��������
//    if(s[i]==')')
//    {
//        return false;
//    }
//    else if(s[i]=='*')//��'*'���ɿո��õ�ʱ�� ����s[i+1] -> s[j]
//    {
//        if(checkValidSubString(s,i+1,j))
//        {
//            return true;
//        }
//    }
//
//    //s[i]=='(' �� s[i]=='*' ����'*'����'('�������
//    for(int k=i+1;k<=j;k++)//�ӵڶ�����ʼ��
//    {
//        //( *  ) ( )
//        //(left) right �ҵڶ�����ʼ��')'����'*'��    �� ��ʱ*����')' ��
//        //left �� right �����Ҳ�ǺϷ�����ȫ���Ϸ�
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



//2.�ݹ��Ż� 
bool checkValidSubString(char *s,int i,int j,int **cache)
{
    if(i>j) return true;//�ݹ��������

    if(cache[i][j]!=0)//�Ѿ���������
    {
        if(cache[i][j]==1)
        return true;
        if(cache[i][j]==-1)
        return false;
    }

    //����û������
    if(s[i]==')')
    {
        cache[i][j]==-1;
        return false;
    }
    else if(s[i]=='*')//��'*'���ɿո��õ�ʱ�� ����s[i+1] -> s[j]
    {
        if(checkValidSubString(s,i+1,j,cache))
        {
            cache[i][j]==1;
            return true;
        }
    }

    //s[i]=='(' �� s[i]=='*' ����'*'����'('�������
    for(int k=i+1;k<=j;k++)//�ӵڶ�����ʼ��
    {
        //( *  ) ( )
        //(left) right �ҵڶ�����ʼ��')'����'*'��    �� ��ʱ*����')' ��
        //left �� right �����Ҳ�ǺϷ�����ȫ���Ϸ�
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
    //0 ������û���
    //1 ��������� Ϊtrue
    //-1��������� Ϊfalse
    return checkValidSubString(s,0,len-1,cache);
}






int main()
{
	char arr[]="(*))";
	printf("%d ",checkValidString(arr));
} 






