#include<iostream>
#include<vector>

using namespace std;


class Solution {
public:
    //�ݹ�ֽ�
    //ˢ�⻹�����õģ���������˼·
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty())
            return result;
        vector<int> seq;
        recursion(result, seq, nums);
        return result;
    }
    void recursion(vector<vector<int>>& result, vector<int>& seq, vector<int> nums)
    {
        if (nums.size() == 1)
        {
            seq.push_back(nums[0]);
            result.push_back(seq);
            seq.pop_back();
            return;
        }
        for (int i = 0; i < nums.size(); i++)
        {
            seq.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            recursion(result, seq, nums);
            nums.insert(nums.begin() + i, seq.back());
            seq.pop_back();
        }
    }
};