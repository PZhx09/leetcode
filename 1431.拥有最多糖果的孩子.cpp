#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    //ʱ�临�Ӷ�O(n),��Ҫ������������
    //�ܲ����Ż���

    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max = -1;
        vector<bool> ans;
        for (int i = 0; i < candies.size(); i++)
        {
            if (max < candies[i])
                max = candies[i];
        }
        for (int i = 0; i < candies.size(); i++)
        {
            if (candies[i] + extraCandies >= max)
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
    }
};