#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:

    //�о����Ƕ�̬�滮
    //f(i)��Ϊ��i�������ʱ����ߵĵ��Խ��
    //��ô���������֪״̬ת�Ʒ���Ϊ��f(i)=max{f(i-1),f(i-2)+nums[i]}
    /*int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int* dp = new int[nums.size() + 1];//�����Ż��ռ临�Ӷ�
        dp[0] = 0;
        dp[1] = nums[0];
        for (int i = 2; i <= nums.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i-1]);
        }
        return dp[nums.size()];
    }*/

    //�Ż��ռ临�Ӷȵķ���
    //������˼��Ŀ�����Ż��ռ临�Ӷȣ�û�뵽ִ��ʱ�䷴�������100%
    //����������ʼ���������������ռ���ʵҲ�˷��˺ܶ�ʱ��
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