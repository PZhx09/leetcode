#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    //借助二维数组暴力便利   69/81  方法是对的，但是时间超时   O(n2)的时间复杂度
    //先尝试在现有方法上优化试试
    /*  方法很蠢，因为自己都想到了用tmp  怎么就没想到其实二维数组不是必要的？
    int subarraySum(vector<int>& nums, int k) {
        int length = nums.size();
        int count = 0;
        int** sum = new int* [length];
        for (int i = 0; i < length; i++)
        {
            sum[i] = new int[length];
            sum[i][i] = nums[i];
            if (nums[i] == k)
                count++;
        }

        //开始计算子数组和     sum[i][j]表示  i->j之间的子数组的和
        for (int i = 0; i < length; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                sum[i][j] = sum[i][j - 1] + nums[j];
                if (sum[i][j] == k)
                    count++;
            }
        }
            
        return count;
    }*/
    //1、枚举法   稍微好一点，但是还是超时
    /*int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j < nums.size(); j++)
            {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }*/
    //很玄学，这样就能过   但是这个方法不是很好
    /*int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int sum = 0;
            for (int j = i; j >= 0; j--)
            {
                sum += nums[j];
                if (sum == k)
                    count++;
            }
        }
        return count;
    }*/
    //2、利用前缀和   以及哈希来搞
    //[i...j]从i到j，值为pre[j]-pre[i-1]也就是说pre[j]-pre[i-1]=k   就可以了
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> pre;
        int sum = 0;
        pre[0]++;//前缀和0先置为1
        for (int j = 0; j < nums.size(); j++)
        {
            sum += nums[j];
            if(pre.find(sum - k)!=pre.end())
                count += pre[sum - k];
            pre[sum]++;
        }
        return count;
    }


};
/*int main()
{
    vector<int> test = { 1,2,3 };
    Solution s1;
    s1.subarraySum(test, 3);
}*/