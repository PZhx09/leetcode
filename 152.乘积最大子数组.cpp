#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
    //�����㷨
    //ͨ������ 184/184������ʱ������  O(n2)��ʱ�临�Ӷ�
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
    //��������  ��������  ��ȥ0  ��0��Ϊ0��   Ȼ��ֻҪ��ż��������������
    //�÷��ε�˼����ˣ���0����������ÿ�����������ż����������ֱ�ӳˡ���������������ȥ����Ǹ�������ȥ�ұ��Ǹ���Ȼ��Ƚ�һ��
    //ʱ�仹�У��ռ临�Ӷ���Щ��
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
                //���������������
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
    //����׼����     ��̬�滮
    //���������������ĺ�����-->��������
    //f max(i) ����ʾ�Ե� i ��Ԫ�ؽ�β�ĳ˻����������ĳ˻�
    //���i�Ǹ�������ô��ϣ��f(i-1)ԽСԽ��
    //���i����������ô��ϣ��f(i-1)Խ��Խ��]
    //�����ȷ������������ռ�vector<int> max vector<int> min   ��ʾ��iΪ��β��������С�˻�
    //����i��״ֻ̬��i-1�й�  ����Ҳ����ֱ����ѭ��
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