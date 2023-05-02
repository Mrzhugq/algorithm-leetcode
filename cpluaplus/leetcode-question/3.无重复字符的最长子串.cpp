#include<stdio.h> 
#include<string.h>
#include<math.h>

//right��ʼֵΪ-1
int lengthOfLongestSubstring(char * s)
{
    int Heap[128] = {0};
    int left = 0, right = -1;
    int ans = 0;
    int len = strlen(s);

    while(left < len)
    {
        if(right+1<len && Heap[s[right+1]] == 0)
        {
            right++;
            Heap[s[right]]++;
        }
        else
        {
            Heap[s[left]]--;
            left++;
        }
        ans = fmax(ans, right-left+1);
    }
    return ans;
}
//�о��������ֺõ㣨�Լ���ͼ��⣩


////right��ʼֵΪ0
// int lengthOfLongestSubstring(char * s)
// {
//     int Heap[128] = {0};
//     int left = 0, right = 0;
//     int ans = 0;
//     int len = strlen(s);
//     while(left < len)
//     {
//         if(right+1<len && Heap[s[right]] == 0)//ע��
//         {
//             Heap[s[right]]++;//ע��
//             right++;
//         }
//         else
//         {
//             Heap[s[left]]--;
//             left++;
//         }
//         ans = fmax(ans, right-left);//ע��
//     }
//     return ans;
// }

int main()
{
	char str[] = "abcabcabc";
	printf("%d ",lengthOfLongestSubstring(str));
	return 0;
}
