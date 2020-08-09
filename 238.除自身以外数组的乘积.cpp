#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //第一想法:暴力  O(n2)  不符合条件
    //第二想法 计算所有乘积，挨个除  O(n)  但是题目要求，不允许用除法

    //看的题解output[i]=L[i]*R[i]  其中L[i]指的是i左边数的乘积，R[i]指的是i右边数的乘积
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;  //L[0]是1  正常应该是分配两个数组L和R，但是这里为了节省空间，直接用了返回的vector
        for (int i = 1; i < nums.size(); i++)
        {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int tmp = 1;
        for (int i = nums.size()-2; i >=0; i--)
        {
            tmp *= nums[i + 1];
            ans[i]*=tmp;
        }
        return ans;
        
    }
};

/*int main()
{
    Solution s1;
    vector<int> test = { 1,2,3,4 };
    s1.productExceptSelf(test);
}*/