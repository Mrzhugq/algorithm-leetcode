//̰��-
//�ֲ����ţ�����strNum[i-1] > strNum[i]��������ǵ�����������
//          ������strNum[i-2]--��Ȼ��strNum[i]=9,���Ա�֤�����󵥵���������
//ȫ�����ţ��õ�С�ڵ���N����󵥵�����������

//���и����⣬�Ӻ���ǰ����ÿλ���Ǵ�ǰ�����أ� �Ӻ���ǰ
//����332�������ǰ��������Ļ��͸ĳ�329�ˣ��������299

class Solution 
{
public:
    int monotoneIncreasingDigits(int n) 
    {
        string strNum = to_string(n);
        int flag = strNum.size();

        for(int i = strNum.size() - 1; i > 0; i--)
        {
            if(strNum[i - 1] > strNum[i])
            {
                strNum[i - 1]--;
                //strNum[i] = '9';  //��������100�����������ȥ��Ҫ��flag��Ǵ����￪ʼ��9

                flag = i;
            }
        }
        for(int i = flag; i < strNum.size(); i++) //��9
        {
            strNum[i] = '9';
        }
        return stoi(strNum);
    }
};
