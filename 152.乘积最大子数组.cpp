#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //暴力算法
    //通过案例 184/184，超出时间限制  O(n2)的时间复杂度
    /*int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int max = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            int ans = 1;
            for (int j = i; j < nums.size(); j++)
            {
                ans *= nums[j];
                max=max>ans?max:ans;
            }
        }
        return max;
    }*/
    //想想性质  整数数组  除去0  乘0就为0了   然后只要有偶数个负数就行了
    //用分治的思想好了，用0来划分区域，每个区域如果是偶数个负数，直接乘。奇数个负数就舍去左边那个，和舍去右遍那个，然后比较一下
    //时间还行，空间复杂度有些差
    /*
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        if (nums.size()==1)
            return nums[0];
        int max = 0;
        int start = 0, end = 0;
        while (start < nums.size())
        {
            int ans = 1;
            while (start < nums.size() && nums[start] == 0)
                start++;
            int iterator = start;
            while (iterator < nums.size() && nums[iterator] != 0)
                iterator ++;
            end = iterator - 1;
            int firstOdd = -1;
            int lastOdd = -1;
            for (int i = start; i <= end; i++)
            {
                ans *= nums[i];
                if (nums[i] < 0)
                {
                    lastOdd = i;
                    if (firstOdd == -1)
                        firstOdd = i;
                }

                
            }
            if (ans < 0)
            {
                //如果有奇数个负数
                if (start!=end)
                {
                    int right = 1;
                    int left = 1;
                    for (int i = firstOdd + 1; i <= end; i++)
                    {
                        right *= nums[i];
                    }
                    for (int i = start; i <= lastOdd - 1; i++)
                    {
                        left *= nums[i];
                    }

                    ans = right > left ? right : left;
                }
            }

            max = max > ans ? max : ans;
            start = end + 2;

        }

        return max;
    }
    */
    //题解标准方法     动态规划
    //和最大连续子数组的和类似-->想想那题
    //f max(i) 开表示以第 i 个元素结尾的乘积最大子数组的乘积
    //如果i是负数，那么他希望f(i-1)越小越好
    //如果i是正数，那么他希望f(i-1)越大越好]
    //可以先分配两个辅助空间vector<int> max vector<int> min   表示以i为结尾的最大和最小乘积
    //但是i的状态只与i-1有关  所以也可以直接用循环
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return NULL;
        int ans = nums[0];
        int maxF = nums[0], minF = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int ax = maxF, in = minF;
            maxF = max(ax * nums[i], max(nums[i], in * nums[i]));
            minF = min(ax * nums[i], min(nums[i], in * nums[i]));
            ans = ans > maxF ? ans : maxF;
        }
        return ans;
    }


};

/*int main()
{
    vector<int> test = { 0,-2,0 };
    Solution s1;

    cout << s1.maxProduct(test);
}*/