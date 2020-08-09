#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    //先用双指针看看能不能过吧  时间复杂度O(m+n)
    //双指针暴力法，近乎于双百   很棒
    /*
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0.0;
        int l1 = 0, l2 = 0;
        int numberOfNum = nums1.size() + nums2.size();//偶数的话是中间两个数取平均数，奇数的话是取中间的那一个数
        int count = (nums1.size() + nums2.size()) / 2;//奇数就是这个，偶数是它的左边和它的平均数
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        if (numberOfNum % 2 == 0)
        {
            //偶数 要考虑到一个数组先遍历完之后的事情
            while (l1 + l2 <= count)
            {
                if (l1 + l2 == count - 1|| l1 + l2 == count)
                {
                    ans += nums1[l1] < nums2[l2] ? nums1[l1] : nums2[l2];
                }
                nums1[l1] < nums2[l2] ? l1++ : l2++;
            }
            ans = ans / 2;
        }
        else
        {
            //奇数
            while (l1 + l2 <= count)
            {
                if ( l1 + l2 == count)
                {
                    ans += nums1[l1] < nums2[l2] ? nums1[l1] : nums2[l2];
                }
                nums1[l1] < nums2[l2] ? l1++ : l2++;
            }
        }
        return ans;
    }
    */
    //采用题解的方法，二分查找
    //两个界限没办法定，那就只定一个界限，另一个界限推出来就行了
    //二分法  一定要注意边界的问题
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);//这里是保证分割线在第二个数组左右两边都一定有元素
        double ans;
        int count = (nums1.size() + nums2.size() + 1) / 2;//中间界限的选取很有意思

        int left = 0, right = nums1.size();
        while (left < right)//最后出来应该是left==right
        {
            int i = (left + right+1) / 2;
            int j = count - i;
            if (nums1[i - 1] > nums2[j])
            {
                right = i - 1;
            }
            else
            {
                left = i;
            }
        }
        int i = left;
        int j = count - left;
        int left1 = i == 0 ? INT_MIN : nums1[i - 1];
        int right1 = i==nums1.size()?INT_MAX:nums1[i];
        int left2 = j==0?INT_MIN:nums2[j - 1];
        int right2 = j==nums2.size()?INT_MAX:nums2[j];
        if ((nums1.size() + nums2.size()) % 2 == 0)
        {
            int l = left1 >left2 ? left1 : left2;
            int r = right1 < right2 ? right1 : right2;
            ans = l + r;
            ans /= 2;
        }
        else
        {
            ans = left1 > left2 ? left1 : left2;
        }
        return ans;
    }
};

/*int main()
{
    Solution s1;
    vector<int> test1 = { 1, 3 };
    vector<int> test2 = { 2 };
    cout<<s1.findMedianSortedArrays(test1, test2)<<endl;
}*/