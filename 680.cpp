#include<iostream>
#include<vector>
#include<string>


using namespace std;

class Solution {
public:
    //��������ʱ
    /*
    bool validPalindrome(string s) {
        //�ȱ�������
        if (isPalincrome(s))
            return true;

        for (int i = 0; i < s.length(); i++)
        {
            if (isPalincrome(s.substr(0, i) + s.substr(i + 1, s.length() - 1 - i)))
                return true;
        }
        return false;
    }

    */
    bool isPalincrome(string s)
    {
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (s[i] != s[s.length() - 1 - i])
                return false;
        }
        return true;
    }
    //˼·û����  ����д�ĺ��ѿ�   ��˫ָ��д  ��һЩ
    /*bool validPalindrome(string s) {
        //���ҹ���
        int i = 0;
        while (i< (s.length() / 2)&&s[i] == s[s.length() - 1 - i])
            i++;
        if (i == s.length() / 2)
            return true;

        string tmp = s;
        tmp.erase(i, 1);
        if (isPalincrome(tmp))
            return true;
        tmp = s;
        tmp.erase(s.length() - 1 - i,1);
        if (isPalincrome(tmp))
            return true;
        return false;
    }*/
    //˫ָ���д��   ������ȥerase
    bool validPalindrome(string s) {
        //���ҹ���
        return validPalindrome(s, 0, s.length() - 1, 0);
    }
    bool validPalindrome(string s, int left, int right, int count)
    {
        if (count > 1)
            return false;
        while (s[left] == s[right] && left < right)
        {
            left++;
            right--;

        }
        if (left == right||left==right+1)
            return true;
        return validPalindrome(s, left + 1, right, count + 1) || validPalindrome(s, left, right - 1, count + 1);
    }
};

/*int main()
{
    string s = "bddb";
    Solution s1;

    cout << s1.validPalindrome(s);

}*/