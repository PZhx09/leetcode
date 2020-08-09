#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //三种想法
    //1、n+1的数组，未出现设为false，出现设为true   不满足条件2   AC但是性能能很差
    //2、排序，然后遍历一遍就行了   不满足条件1
    //3、暴力判断  事件复杂度O(n2)   不满足条件3
    /*int findDuplicate(vector<int>& nums) {
        bool* isAppear = new bool[nums.size() + 1]{ false };
        for (int i = 0; i < nums.size(); i++)
        {
            if (!isAppear[nums[i]])
            {
                isAppear[nums[i]] = true;
            }
            else
            {
                return nums[i];
            }
        }
        return NULL;
    }*/

    //二分查找试试
    //二分查找只适用于有序数组，这里数组是无序的
    //但是cnt[i]是单调递增的！！！！(cnt[i]表示小于等于i的数字个数)
    //对于target左边的数来说cnt[i]<=i    对于target右边的数来说cnt[i]>i
    //1-n个数   n+1的数组   如果target出现两次   那么target左边cnt[i]=i   右遍cnt[j]=j+1
    //考虑target出现三次的情况，这样就有数字不出现了   相当于target替代了未出现的数字
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;//1-n

        while (l < r)
        {
            int mid = (l + r) / 2;//中间是mid
            int cnt = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] <= mid)
                    cnt++;
            }
            if (cnt <= mid)
            {
                l = mid+1;
            }
            else
            {
                r = mid;
            }
        }
        return l;

    }

};

/*int main()
{
    Solution s1;
    vector<int> test = { 1,3,4,2,2 };
    cout<<s1.findDuplicate(test);
}*/