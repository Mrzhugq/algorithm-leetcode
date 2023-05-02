//�����������ȥ�����Ĵ��ڵ���0��ôһ��������һȦ��˵������վ��ļ���վʣ����rest[i]����Ǵ��ڵ���0��
//i��0��ʼ�ۼ�rest[i],�ͼ�ΪcurSum��һ��curSumС��0��
//˵��[0,i]���䶼������Ϊ��ʼλ�ã���ʼλ�ô�i+1�����ٴ�0����curSum

//rest[i] = gas[i] - cost[i]
//̰�ģ��ֲ����ţ���ǰrest[j]��curSumһ��С��0����ʼλ������Ҫ��j+1����Ϊ��j��ʼһ������
//      ȫ�����ţ��ҵ�������һȦ����ʼλ��

class Solution 
{
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int curSum = 0;
        int totalSum = 0;
        int start = 0;

        for(int  i = 0; i < gas.size(); i++)
        {
            curSum += gas[i] - cost[i]; 
            totalSum += gas[i] - cost[i]; 
            if(curSum < 0)
            {
                start = i + 1; //��ʼλ�ø���Ϊi+1
                curSum = 0;    //curSum��0��ʼ
            }
        }
        if(totalSum < 0)  return -1; //˵����ôҲ��������һȦ
        return start;
    }
};




/*
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]

       [-2, -2, -2, 3, 3]
*/
