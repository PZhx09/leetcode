#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    //��������������
    //��Ȼ�������ִ����ж��Ƿ��ǻ����Ӵ����ǵĻ�����    ʱ�临�Ӷ�(s.length()3)   ������Ȼ����ȥ��
    //��������������ʱ�临�Ӷ�   
    //������ô�Ż�   i��j��  i+1  j-1�϶�Ҳ�ǡ�                i+1 j-1����  ��ôi  j�϶�Ҳ����
/*    string longestPalindrome(string s) {
        string ans;
        int maxLength = 0;

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (maxLength < j - i + 1&&isPalindrome(s, i, j))
                {
                    maxLength = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
    bool isPalindrome(string s, int i, int j)
    {
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    */
    //���ҹ��ɣ�   i-j��   ��ôi+1   j-1 �϶�Ҳ��   i+1 j-1����   ��ôi   j�϶�Ҳ����
    //�Ż�֮�� ʱ�临�Ӷ�(s.length()2)
    //�Լ���ķ��������Ѿ��ܿ�����̬�滮�ĳ�����   �����˼��Ǵ�С����    �����ﲻ̫��
    string longestPalindrome(string s) {
        string ans;
        int maxLength = 0;
        bool** isP = new bool* [s.length()];
        for (int i = 0; i < s.length(); i++)
            isP[i] = new bool[s.length()];

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                isP[i][j] = true;
            }
        }

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (isP[i][j])
                {
                    if (s[i] != s[j])
                    {
                        int row = i, column = j;

                        while (row >= 0 && column < s.length())
                        {
                            isP[row][column] = false;
                            row--;
                            column++;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = i; j < s.length(); j++)
            {
                if (isP[i][j]&&maxLength<j-i+1)
                {
                    maxLength = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }


    string longestPalindrome(string s) {
        string ans;
        int maxLength = 0;
        bool** isP = new bool* [s.length()];
        for (int i = 0; i < s.length(); i++)
            isP[i] = new bool[s.length()]{false};


        //���ﶯ̬�滮��ѭ���Ƚ�����˼   ���������ǰ����i  j  ˫forѭ������ͷ���״̬ת�Ƹ�����
        //���������ѭ����l(����)��ѭ����   ��ѭ������1 ��ѭ������2   ѭ������3(3��Ҫ�õ�1��״̬��)
        //��̬�滮  ע����״̬ת�ƣ�������
        for (int l = 0; l < s.length(); l++)//l���ִ�����
        {
            for (int i = 0; i + l < s.length(); i++)//i���ִ����
            {
                int j = i + l;//j���ִ��յ�  ���ѭ�� ����Ϊ���ж�i--j�Ƿ��ǻ��Ĵ�
                if (l == 0)//�ִ�����Ϊ1
                {
                    isP[i][j] = true;
                }
                else if (l == 1)
                {
                    isP[i][j] = s[i]==s[j];
                }
                else
                {
                    isP[i][j] = isP[i + 1][j - 1] && (s[i] == s[j]);
                }
                if (isP[i][j] && maxLength < l + 1)
                {
                    maxLength = l + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }

        return ans;
    }
    //����һ��������չ��   �о����������
    //ö�����еĻ�������(Ҫôһ���ַ���Ҫô�����ַ�)��Ȼ����������չ  ֱ�����ǻ���
};

int main()
{
    string s = "babad";
    Solution s1;
    cout << s1.longestPalindrome(s)<<endl;
}