#include<iostream>
using namespace std;

class Solution {
public:
    //思路正确。通过14/19，超出时间限制
    //原因是递归的时候进行了大量重复
    /*
    int numTrees(int n) {

        if (n <= 1)
            return 1;
        //选定根节点，然后根节点左子树的数目+右子树的数目=当前选择根节点存在的二叉搜索树数目
        int sum = 0;
        for (int i = 1; i <= n; i++)//i是根节点
        {
            sum += numTrees(i - 1) * numTrees(n-i);
        }
        return sum;

    }
    */
    int* result = new int[30];
    int now = 1;
    int numTrees(int n) {
        for (int i = 0; i < 30; i++)
            result[i] = 1;
        return claculate(n);
    }
    int claculate(int n)
    {
        if (n <= now)
            return result[n];
        //选定根节点，然后根节点左子树的数目+右子树的数目=当前选择根节点存在的二叉搜索树数目
        int sum = 0;
        for (int i = 1; i <= n; i++)//i是根节点
        {
            sum += claculate(i - 1) * claculate(n - i);
        }
        now = now > n ? now : n;
        result[n] = sum;
        return sum;
    }
};

/*int main()
{
    Solution s1;
    cout<<s1.numTrees(3);
}*/