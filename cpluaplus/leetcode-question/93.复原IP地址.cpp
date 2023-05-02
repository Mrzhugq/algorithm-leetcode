
class Solution 
{
private:
    vector<string> reault;
    bool IsValid(string &s, int start, int end) //�ж�s������[start,end]�Ƿ�Ϸ�
    {
        if(start > end) return false;
        if(s[start] == '0' && start != end) //��һ��Ϊ0���Ϸ�
        {
            return false;
        }
        int sum = 0;
        for(int i=start; i<=end; i++)
        {
            if(s[i] < '0' || s[i] >'9') //�������ַ����Ϸ�
            {
                return false;
            }
            sum = sum *10 + (s[i] - '0');
            if(sum > 255) //����255���Ϸ�
            {
                return false;
            }
        }
        return true;
    }
    void backtracking(string &s, int startIndex, int pointNum)
    {
        if(pointNum == 3) //������������и���Ķ��ˣ����ж�һ�����һ���Ƿ�Ϸ����Ϸ��ͼ���result
        {
            if(IsValid(s, startIndex, s.size()-1))
            reault.push_back(s);
            return;
        }

        for(int i=startIndex; i<s.size(); i++)
        {
            //[startIndex, i] ����ÿ���и�����䣬����131��
            if(IsValid(s, startIndex, i))
            {
                s.insert(i+1, 1, '.'); //�ٺϷ��������һλ����һ��'.'
                //s.insert(s.begin() + i + 1 , '.');
                ++pointNum;   
                backtracking(s, i+2, pointNum);
                //i+2 һ��������Ϊ����Ϊ�����ظ�ѡȡ����һ������Ϊ������'.' , ��Ҫ���������
                s.erase(i+1, 1); //ɾ�����'.'
                //s.erase(s.begin() + i + 1);
                --pointNum;
            }
            else
            {
                //�����Ͼ�ֱ��break����Ϊ�Ѿ����Ϸ��ˣ������û��Ҫ���и���
                //����ӵ�ǰ���startIndex��ʼ�е�i�Ѿ�������ǰ��0�ˣ������Ѿ�����255�ˣ�û��Ҫ��������
                break;
            }
        }
    }
public:
    vector<string> restoreIpAddresses(string s) 
    {
        reault.clear();
        if(s.size() < 4 || s.size() > 12) return reault;
        backtracking(s, 0, 0);
        return reault;
    }
};
