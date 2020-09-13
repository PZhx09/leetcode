#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    //t�п������ظ�����ĸ��������û�п��ǵ��ظ��ַ�������        ��һ��map���ˣ�������¼t������ַ�����Ŀ

    //�ܽ�   ˼·û��
    //����������map���������ÿ�   count���Ա���(û��Ҫȫ��check)
    //s.length����unsigned int�ͱ�����ע�ⲻ�ܺ͸����Ƚ�
    string minWindow(string s, string t) {

        map<char, int> numInT;
        for (int i = 0; i < t.length(); i++)
            numInT[t[i]]++;

        int* numChar = new int[t.length()]{0};
        int count = 0;
        int lengthS = s.length();
        int lengthT = t.length();
        int minlength = s.length() + 1;
        string ans;
        int low = 0, high = -1;
        //����д����Щ�ѿ������Կ���ÿ��ֻ�ƽ�һ����ĸ   û��Ҫһ��while�ƽ�����
        //numChar���������map�����ÿ�   ���Լ���t.find
        while (high < lengthS)//s.length���޷������������ܺ������Ƚ�
        {
            while (high < lengthS && count < numInT.size()) //���ұ߽�
            {
                high++;
                int pos = t.find(s[high]);
                if (pos !=-1)
                {
                    numChar[pos]++;
                    if (numChar[pos] == numInT[s[high]])
                    {
                        count++;
                    }
                }
                
            }
            if (count < numInT.size())
                break;
            while (low <=high && count == numInT.size()) //����߽�
            {
                
                if (minlength > high - low + 1)
                {
                    minlength = high - low + 1;
                    ans = s.substr(low, high - low + 1);
                }
                int pos = t.find(s[low]);
                if (pos != -1)
                {
                    if (numChar[pos] == numInT[s[low]])
                    {
                        count--;
                    }
                    numChar[pos]--;

                }
                low++;
                
            }
        }
        return ans;
    }
};

/*int main()
{
    Solution s1;
    string s = "aa";
    string t = "aa";
    cout << s1.minWindow(s, t)<<endl;
}*/