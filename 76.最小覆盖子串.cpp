#include<iostream>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    //t中可能有重复的字母，我这里没有考虑到重复字符的问题        加一个map好了，用来记录t里面的字符的数目

    //总结   思路没错
    //但是用两个map代码更快更好看   count可以保留(没必要全部check)
    //s.length返回unsigned int型变量，注意不能和负数比较
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
        //代码写的有些难看，可以考虑每次只推进一个字母   没必要一个while推进到底
        //numChar这个数组用map来更好看   可以减少t.find
        while (high < lengthS)//s.length是无符号整数，不能和正数比较
        {
            while (high < lengthS && count < numInT.size()) //推右边界
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
            while (low <=high && count == numInT.size()) //推左边界
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