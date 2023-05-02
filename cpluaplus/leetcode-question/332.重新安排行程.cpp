//所有的机票 必须都用一次 且 只能用一次

class Solution 
{
private:
    //unordered_map<出发机场, map<到达机场, 航班次数>> targets;      (map会自动按字典排序)
    unordered_map<string, map<string, int>> targets;
    bool backtracking(int ticketNum, vector<string>& reslut)
    {
        if(reslut.size() == ticketNum+1)
        {
            return true;
        }
        for(pair<const string, int>& target : targets[reslut[reslut.size()-1]])
        {
            if(target.second > 0)  // 记录到达机场是否?过了
            {
                reslut.push_back(target.first);
                target.second--;
                if(backtracking(ticketNum, reslut)) return true; 
                //找到一个返回进行了，因为只要一个最小的行程组合
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
            targets[vec[0]][vec[1]]++;   // 记录映射关系
        }
        reslut.push_back("JFK"); // 起始机场
        backtracking(tickets.size(), reslut);
        return reslut;
    }
};
