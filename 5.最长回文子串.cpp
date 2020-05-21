#include<iostream>
#include<string>

using namespace std;


class Solution {
public:
    //先来个暴力遍历
    //既然是所有字串都判定是否是回文子串，是的话返回    时间复杂度(s.length()3)   这样显然过不去啊
    //暴力遍历，超出时间复杂度   
    //想想怎么优化   i到j是  i+1  j-1肯定也是。                i+1 j-1不是  那么i  j肯定也不是
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
    //找找规律？   i-j是   那么i+1   j-1 肯定也是   i+1 j-1不是   那么i   j肯定也不是
    //优化之后 时间复杂度(s.length()2)
    //自己想的方法，就已经能看出动态规划的雏形了   但是人家是从小到大    我这里不太对
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


        //这里动态规划的循环比较有意思   如果按照以前那种i  j  双for循环，你就发现状态转移跟不上
        //所以这里的循环是l(长度)在循环面   先循环长度1 在循环长度2   循环长度3(3就要用到1的状态了)
        //动态规划  注意找状态转移！！！！
        for (int l = 0; l < s.length(); l++)//l是字串长度
        {
            for (int i = 0; i + l < s.length(); i++)//i是字串起点
            {
                int j = i + l;//j是字串终点  这次循环 就是为了判断i--j是否是回文串
                if (l == 0)//字串长度为1
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
    //还有一个中心扩展法   感觉更容易理解
    //枚举所有的回文中心(要么一个字符，要么两个字符)，然后向左右扩展  直至不是回文
};

int main()
{
    string s = "babad";
    Solution s1;
    cout << s1.longestPalindrome(s)<<endl;
}