//ͳ�Ƴ������ַ�����26���ַ��ĳ��ֵ�Ƶ�ʣ�Ȼ��ȡÿ���ַ�Ƶ�ʵ���Сֵ�����ת�������ʽ�Ϳ���

class Solution 
{
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<string> res;
        int hash[26] = {0};
        for(int j=0; j<words[0].size(); j++)// ���õ�һ���ַ�����ʼ��hash
        {
            hash[words[0][j] - 'a']++;
        }

        int hashOtherStr[26] = {0};
        for(int i=1; i<words.size(); i++)
        {
            memset(hashOtherStr, 0, 26*sizeof(int)); //hashOtherStrÿ�ζ�����
            for(int j=0; j<words[i].size(); j++)
            {
                hashOtherStr[words[i][j] - 'a']++;
            }
            for(int k=0; k<26; k++)
            {
                hash[k] = min(hash[k], hashOtherStr[k]);
            }
        }
        //��Ƶ��ת��Ϊ�ַ���
        for(int i=0; i<26; i++)
        {
            while(hash[i] != 0) //ע��������while���������ظ��ַ�
            {
                string str(1, (char)i+'a');
                res.push_back(str);
                hash[i]--;
            }
        }
        return res;
    }
};
