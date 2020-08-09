#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    //感觉又是动态规划
    //f(i)记为到i这个房间时，最高的盗窃金额
    //那么根据题意可知状态转移方程为，f(i)=max{f(i-1),f(i-2)+nums[i]}
    /*int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int* dp = new int[nums.size() + 1];//可以优化空间复杂度
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i-1]);
        }
        return dp[nums.size()];
    }*/

    //优化空间复杂度的方法
    //很有意思，目的是优化空间复杂度，没想到执行时间反而变成了100%
    //这表明数组初始化或者是数组分配空间其实也浪费了很多时间
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int num0 = 0;
        int num1 = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            int tmp = num1;
            num1 = max(num0 + nums[i - 1], num1);
            num0 = tmp;
        }
        return num1;
    }
};
/*int main()
{
    Solution s1;
    vector<int> test = { 1,2,3,1 };
    s1.rob(test);
}*/