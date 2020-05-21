#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //n�ʺ�����
    //��ȫ���У�Ȼ�����ж�����
    //�����vector<string>����һ�ֽⷨ��ÿ��string��һ��
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
        //��ʼȫ����
        if (cursor == n - 1)//�����һ����
        {
            if (judge(permutationArray))
                ans.push_back(initializePermutation(permutationArray));
        }
        else//δ�����һ��
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
        //���ø���������������������ֵ  �����������߼Ӽ�   ����Ҫע��  ���������������������� ���������һ��
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
    bool judge(vector<int> permutationArray)//ȫ���еõ�һ�ν�������ж�һ�Σ�������ֲ���ͻ�ͼӵ�ans��
    {
        //����б��
        for (int i = 0; i < permutationArray.size()-1; i++)//���һ�в���Ҫ�ж�
        {
            for (int j = 1; i+j < permutationArray.size(); j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//���ҵ�б��
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//�����б��
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
        //��ʼȫ����
        if (cursor == n - 1)//�����һ����
        {
            if (judge(permutationArray, cursor))
                ans.push_back(initializePermutation(permutationArray));
            
        }
        else//δ�����һ��
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
        //���ø���������������������ֵ  �����������߼Ӽ�   ����Ҫע��  ���������������������� ���������һ��
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
    bool judge(vector<int> permutationArray)//ȫ���еõ�һ�ν�������ж�һ�Σ�������ֲ���ͻ�ͼӵ�ans��
    {
        //����б��
        for (int i = 0; i < permutationArray.size() - 1; i++)//���һ�в���Ҫ�ж�
        {
            for (int j = 1; i + j < permutationArray.size(); j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//���ҵ�б��
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//�����б��
                    return false;
            }
        }
        return true;
    }
    //������ж�ʱ�临�ӶȺͿռ临�Ӷȸ��ˣ��м���м�֦����
    bool judge(vector<int> permutationArray,int cursor)
    {
        //����б��
        for (int i = 0; i < cursor; i++)
        {
            for (int j = 1; i + j <= cursor; j++)
            {
                if (permutationArray[i + j] == permutationArray[i] + j)//���ҵ�б��
                    return false;
                if (permutationArray[i + j] == permutationArray[i] - j)//�����б��
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