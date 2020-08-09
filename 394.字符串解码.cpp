#include<iostream>

#include<string>
using namespace std;


class Solution {
public:
    //第一遍想的时候，没有考虑括号嵌套的情况
    /*
        string decodeString(string s) {
            string ans;
            int times=0;
            string characterInBracket;
            bool isInBracket=false;
            for(int i=0;i<s.length();i++)
            {
                //四种情况  数字    字母(又分为括号内、括号外)    左括号(开始记录括号内)  右括号(结束记录括号内)
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
    //还是想想递归的思路吧  
    string decodeString(string s) {
        string ans;
        int times = 0;
        for (int i = 0; i < s.length(); i++)
        {
            //分为三种情况  左括号  字母   数字
            if ('0' <= s[i] && s[i] <= '9')
            {
                times = times * 10 + s[i] - '0';
            }
            else if (s[i] == '[')
            {
                //遇到左括号，找对应的右括号
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
    //这题用堆栈的思想也不错

};