
//�̶��������� + ��ϣ
class Solution 
{
private:
    bool IsEqual(int* arr1, int* arr2)
    {
        for(int i=0; i<26; i++)
        {
            if(arr1[i] != arr2[i])
            {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) 
    {
        vector<int> res;
        if(p.size() > s.size())
        {
            return res;
        }
        int s_cnt[26] = {0};
        int p_cnt[26] = {0};
        
        for(int i=0; i<p.size(); i++)
        {
            s_cnt[s[i] - 'a']++;
            p_cnt[p[i] - 'a']++;
        }
        if(IsEqual(s_cnt, p_cnt))
        {
            res.push_back(0);
        }

        int left = 0;
        int right = p.size(); //�̶�����[left, right-1]    //ע��right��ʵ����
        for(; right<s.size(); right++)                    //ע��ѭ����������
        {
            s_cnt[s[right] - 'a']++;
            s_cnt[s[left] - 'a']--;
            left++;
            if(IsEqual(s_cnt, p_cnt))
            {
                res.push_back(left);
            }
        }

        // int left = 0;
        // int right = p.size() - 1; //�̶�����[left, right]
        // while(right < s.size()-1)
        // {
        //     s_cnt[s[++right] - 'a']++;
        //     s_cnt[s[left++] - 'a']--;
        //     if(IsEqual(s_cnt, p_cnt))
        //     {
        //         res.push_back(left);
        //     }           
        // }
        return res;
    }
};
