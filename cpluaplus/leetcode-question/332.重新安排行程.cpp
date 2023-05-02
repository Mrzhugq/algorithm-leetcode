//���еĻ�Ʊ ���붼��һ�� �� ֻ����һ��

class Solution 
{
private:
    //unordered_map<��������, map<�������, �������>> targets;      (map���Զ����ֵ�����)
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& reslut)
    {
        if(reslut.size() == ticketNum+1)
        {
            return true;
        }
        for(pair<const string, int>& target : targets[reslut[reslut.size()-1]])
        {
            if(target.second > 0)  // ��¼��������Ƿ�?����
            {
                reslut.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, reslut)) return true; 
                //�ҵ�һ�����ؽ����ˣ���ΪֻҪһ����С���г����
                reslut.pop_back();
                target.second++;
            }
        }
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        targets.clear();
        vector<string> reslut;
        for(const vector<string>& vec : tickets)
        {
            targets[vec[0]][vec[1]]++;   // ��¼ӳ���ϵ
        }
        reslut.push_back("JFK"); // ��ʼ����
        backtracking(tickets.size(), reslut);
        return reslut;
    }
};
