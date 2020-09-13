#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //��һ�뷨:����  O(n2)  ����������
    //�ڶ��뷨 �������г˻���������  O(n)  ������ĿҪ�󣬲������ó���

    //�������output[i]=L[i]*R[i]  ����L[i]ָ����i������ĳ˻���R[i]ָ����i�ұ����ĳ˻�
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());
        ans[0] = 1;  //L[0]��1  ����Ӧ���Ƿ�����������L��R����������Ϊ�˽�ʡ�ռ䣬ֱ�����˷��ص�vector
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