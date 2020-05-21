#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //n皇后问题
    //先全排列，然后再判定试试
    //输出里vector<string>代表一种解法，每个string是一行
    /*vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n <= 0)
            return ans;
        vector<int> permutationArray;
        for (int i = 0; i < n; i++)
            permutationArray.push_back(i);
        Permutation(permutationArray, 0, ans, n);

        return ans;
    }
    void Permutation(vector<int>& permutationArray, int cursor, vector<vector<string>>& ans,int n)//zheli1
    {
        //开始全排列
        if (cursor == n - 1)//到最后一行了
        {
            if (judge(permutationArray))
                ans.push_back(initializePermutation(permutationArray));
        }
        else//未到最后一行
        {
            for (int i = cursor; i < permutationArray.size(); i++)
            {
                swap(permutationArray, cursor, i);
                Permutation(permutationArray, cursor + 1, ans, n);
                swap(permutationArray, i, cursor);
            }
        }
    }
    void swap(vector<int>& array, int i, int j)
    {
        //不用辅助变量交换两个变量的值  可以用异或或者加减   但是要注意  必须是两个变量！！！！ 这里可能是一个
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    vector<string> initializePermutation(vector<int> permutationArray)
    {
        vector<string> charPermutation;
        for (int i = 0; i < permutationArray.size();i++)
        {
            string tmp(permutationArray.size(), '.');
            tmp[permutationArray[i]] = 'Q';
            charPermutation.push_back(tmp);
        }
        return charPermutation;
        
    }
    bool judge(vector<int> permutationArray)//全排列得到一次结果，就判断一次，如果发现不冲突就加到ans里
    {
        //两条斜线
        for (int i = 0; i < permutationArray.size()-1; i++)//最后一行不需要判定
        {
            for (int j = 1; i+j < permutationArray.size(); j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//向右的斜线
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//向左的斜线
                    return false;
            }
        }
        return true;
    }*/
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        if (n <= 0)
            return ans;
        vector<int> permutationArray;
        for (int i = 0; i < n; i++)
            permutationArray.push_back(i);
        Permutation(permutationArray, 0, ans, n);

        return ans;
    }
    void Permutation(vector<int>& permutationArray, int cursor, vector<vector<string>>& ans, int n)//zheli1
    {
        //开始全排列
        if (cursor == n - 1)//到最后一行了
        {
            if (judge(permutationArray, cursor))
                ans.push_back(initializePermutation(permutationArray));
            
        }
        else//未到最后一行
        {
            for (int i = cursor; i < permutationArray.size(); i++)
            {
                swap(permutationArray, cursor, i);
                if (judge(permutationArray,cursor))
                    Permutation(permutationArray, cursor + 1, ans, n);
                
                swap(permutationArray, i, cursor);
            }
        }
    }
    void swap(vector<int>& array, int i, int j)
    {
        //不用辅助变量交换两个变量的值  可以用异或或者加减   但是要注意  必须是两个变量！！！！ 这里可能是一个
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    vector<string> initializePermutation(vector<int> permutationArray)
    {
        vector<string> charPermutation;
        for (int i = 0; i < permutationArray.size(); i++)
        {
            string tmp(permutationArray.size(), '.');
            tmp[permutationArray[i]] = 'Q';
            charPermutation.push_back(tmp);
        }
        return charPermutation;

    }
    bool judge(vector<int> permutationArray)//全排列得到一次结果，就判断一次，如果发现不冲突就加到ans里
    {
        //两条斜线
        for (int i = 0; i < permutationArray.size() - 1; i++)//最后一行不需要判定
        {
            for (int j = 1; i + j < permutationArray.size(); j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//向右的斜线
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//向左的斜线
                    return false;
            }
        }
        return true;
    }
    //最后再判断时间复杂度和空间复杂度感人，中间进行剪枝好了
    bool judge(vector<int> permutationArray,int cursor)
    {
        //两条斜线
        for (int i = 0; i < cursor; i++)
        {
            for (int j = 1; i + j <= cursor; j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//向右的斜线
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//向左的斜线
                    return false;
            }
        }
        return true;
    }
};

/*int main()
{
    Solution s1;
    cout<<s1.solveNQueens(4).size();
    cout << "hello" << endl;
}*/