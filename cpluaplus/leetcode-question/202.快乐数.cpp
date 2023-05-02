
//-----------------------------------------------------------------------------------------
//����ָ�뷨���������ж��Ƿ�Ϊѭ�������Ƶ�

class Solution 
{
private:
    int GetSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) 
    {
        int slow = n;
        int fast = GetSum(n);
        while(slow != fast)
        {
            fast = GetSum(fast); //fast��������slow��һ��,�粻�ǿ��������ǻ����һ��Ȧ�����ն������һ������1����
            fast = GetSum(fast); //����ǿ��������������ն������1
            slow = GetSum(slow);
        }
        return (slow == 1);
    }
};

//--------------------------------------------------------------------------------------------
//ע����Ŀ˵�Ŀ�������ѭ��(�ؼ�)������1
//���Կ���unorder_set�ж��Ƿ���ֹ�

class Solution 
{
private:
    int GetSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) 
    {
        unordered_set<int> st;
        while(true)
        {
            int sum = GetSum(n);
            if(sum == 1)
            {
                return true;
            }
            //�����������ֹ���˵���Ѿ���������ѭ���ˣ���������false
            if(st.find(sum) != st.end())
            {
                return false;
            }
            else
            {
                st.insert(sum);
            }
            n = sum;
        }
    }
};//ע����Ŀ˵�Ŀ�������ѭ��(�ؼ�)������1
//���Կ���unorder_set�ж��Ƿ���ֹ�

class Solution 
{
private:
    int GetSum(int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) 
    {
        unordered_set<int> st;
        while(true)
        {
            int sum = GetSum(n);
            if(sum == 1)
            {
                return true;
            }
            //�����������ֹ���˵���Ѿ���������ѭ���ˣ���������false
            if(st.find(sum) != st.end())
            {
                return false;
            }
            else
            {
                st.insert(sum);
            }
            n = sum;
        }
    }
}; 
