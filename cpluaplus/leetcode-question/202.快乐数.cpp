
//-----------------------------------------------------------------------------------------
//快慢指针法，类似于判断是否为循环链表似的

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
            fast = GetSum(fast); //fast走两步，slow走一步,如不是快乐数它们会进入一个圈，最终都会等于一个不是1的数
            fast = GetSum(fast); //如果是快乐数，它们最终都会等于1
            slow = GetSum(slow);
        }
        return (slow == 1);
    }
};

//--------------------------------------------------------------------------------------------
//注意题目说的可能无线循环(关键)，或者1
//所以可用unorder_set判断是否出现过

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
            //如果这个数出现过，说明已经陷入无限循环了，立即返回false
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
};//注意题目说的可能无线循环(关键)，或者1
//所以可用unorder_set判断是否出现过

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
            //如果这个数出现过，说明已经陷入无限循环了，立即返回false
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
