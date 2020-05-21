#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


class Solution {
public:
    //������ά���鱩������   69/81  �����ǶԵģ�����ʱ�䳬ʱ   O(n2)��ʱ�临�Ӷ�
    //�ȳ��������з������Ż�����
    /*  �����ܴ�����Ϊ�Լ����뵽����tmp  ��ô��û�뵽��ʵ��ά���鲻�Ǳ�Ҫ�ģ�
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

        //��ʼ�����������     sum[i][j]��ʾ  i->j֮���������ĺ�
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
    //1��ö�ٷ�   ��΢��һ�㣬���ǻ��ǳ�ʱ
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
    //����ѧ���������ܹ�   ��������������Ǻܺ�
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
    //2������ǰ׺��   �Լ���ϣ����
    //[i...j]��i��j��ֵΪpre[j]-pre[i-1]Ҳ����˵pre[j]-pre[i-1]=k   �Ϳ�����
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> pre;
        int sum = 0;
        pre[0]++;//ǰ׺��0����Ϊ1
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