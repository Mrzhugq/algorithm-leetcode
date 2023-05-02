//很多数组类填充的问题，都可以先预先给数组扩容，然后在从后往前进行操作

//从后往前填充O(N)的好处：1.不用申请新的数组 
//                      2.避免了从前往后填充元素O(N^2)要来的每次添加元素都要将添加元素之后的所有元素都往后移送

class Solution 
{
public:
    string replaceSpace(string s) 
    {
        int count = 0;
        int OldSize = s.size();
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                count++;
            }
        }
        s.resize(s.size() + 2 * count); //先扩充到空格替换为%20后的大小
        int NewSize = s.size();         //这时的s.size()已经是OldSize+2*count了
        
        //利用双指针从后往前进行填充
        for(int i=OldSize-1, j=NewSize-1; i<j; i--,j--) //i<j -> i==j结束循环，很妙
        {
            if(s[i] != ' ')
            {
                s[j] = s[i];
            }
            else ///s[i] == ' '
            {
                s[j] = '0';
                s[j-1] = '2';
                s[j-2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};
