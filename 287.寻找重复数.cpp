#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //�����뷨
    //1��n+1�����飬δ������Ϊfalse��������Ϊtrue   ����������2   AC���������ܺܲ�
    //2������Ȼ�����һ�������   ����������1
    //3�������ж�  �¼����Ӷ�O(n2)   ����������3
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

    //���ֲ�������
    //���ֲ���ֻ�������������飬���������������
    //����cnt[i]�ǵ��������ģ�������(cnt[i]��ʾС�ڵ���i�����ָ���)
    //����target��ߵ�����˵cnt[i]<=i    ����target�ұߵ�����˵cnt[i]>i
    //1-n����   n+1������   ���target��������   ��ôtarget���cnt[i]=i   �ұ�cnt[j]=j+1
    //����target�������ε�����������������ֲ�������   �൱��target�����δ���ֵ�����
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;//1-n

        while (l < r)
        {
            int mid = (l + r) / 2;//�м���mid
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