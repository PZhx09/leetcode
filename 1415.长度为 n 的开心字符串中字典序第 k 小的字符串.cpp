#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    //第一个想法，全排列，列出来然后返回第k个
    //但是这个显然时间复杂度和空间复杂度都爆表

    //利用k直接定位
    //下面可以注意到k-1的问题，因为这里不是从0开始的，所以有这个问题，那么不如开始就k-1让他从0开始
    //注意点 1、 k-1  从0开始
    //2、base的变化
    /*string getHappyString(int n, int k) {
        string ans;
        if (k < 0 || k>3 * pow(2, n - 1))
            return "";
        int base = pow(2, n - 1);
        k=k - 1;
        ans += 'a' + k / base;
        k = k % base;
        base=base >> 1;
        n--;
        char last = ans[0];
        
        while (n)
        {
            int tmp = k / base;
            switch (last)
            {
            case 'a':
                if (tmp)
                {
                    ans += 'c';
                    last = 'c';
                }
                else
                {
                    ans += 'b';
                    last = 'b';
                }
                break;
            case 'b':
                if (tmp)
                {
                    ans += 'c';
                    last = 'c';
                }
                else
                {
                    ans += 'a';
                    last = 'a';
                }
                break;
            case 'c':
                if (tmp)
                {
                    ans += 'b';
                    last = 'b';
                }
                else
                {
                    ans += 'a';
                    last = 'a';
                }
                break;
            }
            n--;
            k = k % base;
            base = base >> 1;
        }
        return ans;
    }*/
    //写法上进行优化
    string getHappyString(int n, int k) {
        string ans;
        if (k < 0 || k>3 * pow(2, n - 1))
            return "";
        int base = pow(2, n - 1);
        k = k - 1;
        ans += 'a' + k / base;
        k = k % base;
        base = base >> 1;
        n--;
        char last = ans[0];
        vector <vector<char>> data= { {'b', 'c'}, { 'a','c' }, { 'a','b' }};


        while (n)
        {
            int tmp = k / base;
            ans += data[last - 'a'][tmp];
            last = data[last - 'a'][tmp];
            n--;
            k = k % base;
            base = base >> 1;
        }
        return ans;
    }
};
/*int main()
{
    Solution s1;
   cout<< s1.getHappyString(7, 8);
}*/
