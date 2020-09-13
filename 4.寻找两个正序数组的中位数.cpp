#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    //����˫ָ�뿴���ܲ��ܹ���  ʱ�临�Ӷ�O(m+n)
    //˫ָ�뱩������������˫��   �ܰ�
    /*
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double ans=0.0;
        int l1 = 0, l2 = 0;
        int numberOfNum = nums1.size() + nums2.size();//ż���Ļ����м�������ȡƽ�����������Ļ���ȡ�м����һ����
        int count = (nums1.size() + nums2.size()) / 2;//�������������ż����������ߺ�����ƽ����
        nums1.push_back(INT_MAX);
        nums2.push_back(INT_MAX);
        if (numberOfNum % 2 == 0)
        {
            //ż�� Ҫ���ǵ�һ�������ȱ�����֮�������
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
            //����
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
    //�������ķ��������ֲ���
    //��������û�취�����Ǿ�ֻ��һ�����ޣ���һ�������Ƴ���������
    //���ַ�  һ��Ҫע��߽������
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);//�����Ǳ�֤�ָ����ڵڶ��������������߶�һ����Ԫ��
        double ans;
        int count = (nums1.size() + nums2.size() + 1) / 2;//�м���޵�ѡȡ������˼

        int left = 0, right = nums1.size();
        while (left < right)//������Ӧ����left==right
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