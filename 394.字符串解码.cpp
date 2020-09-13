#include<iostream>

#include<string>
using namespace std;


class Solution {
public:
    //��һ�����ʱ��û�п�������Ƕ�׵����
    /*
        string decodeString(string s) {
            string ans;
            int times=0;
            string characterInBracket;
            bool isInBracket=false;
            for(int i=0;i<s.length();i++)
            {
                //�������  ����    ��ĸ(�ַ�Ϊ�����ڡ�������)    ������(��ʼ��¼������)  ������(������¼������)
                switch(s[i])
                {
                    case '0'...'9':
                    times=times*10+s[i]-'0';
                    break;
                    case '[':
                    isInBracket=true;
                    break;
                    case ']':
                    isInBracket=false;
                    while(times)
                    {
                        times--;
                        ans+=characterInBracket;
                    }
                    characterInBracket.clear();
                    break;
                    default:
                    if(isInBracket)
                    {
                        characterInBracket+=s[i];
                    }
                    else
                    {
                        ans+=s[i];
                    }
                    break;

                }
            }
            return ans;
        }*/
    //��������ݹ��˼·��  
    string decodeString(string s) {
        string ans;
        int times = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //��Ϊ�������  ������  ��ĸ   ����
            if ('0' <= s[i] && s[i] <= '9')
            {
                times = times * 10 + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                //���������ţ��Ҷ�Ӧ��������
                int count = 1;
                int j = i;
                while (count)
                {
                    j++;
                    if (s[j] == ']')
                        count--;
                    if (s[j] == '[')
                        count++;
                }
                string tmp = decodeString(s.substr(i + 1, j - i - 1));
                while (times)
                {
                    ans += tmp;
                    times--;
                }
                i = j;
            }
            else
            {
                ans += s[i];
            }

        }
        return ans;
    }
    //�����ö�ջ��˼��Ҳ����

};