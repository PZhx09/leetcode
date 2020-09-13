#include<iostream>
using namespace std;

class Solution {
public:
    //˼·��ȷ��ͨ��14/19������ʱ������
    //ԭ���ǵݹ��ʱ������˴����ظ�
    /*
    int numTrees(int n) {

        if (n <= 1)
            return 1;
        //ѡ�����ڵ㣬Ȼ����ڵ�����������Ŀ+����������Ŀ=��ǰѡ����ڵ���ڵĶ�����������Ŀ
        int sum = 0;
        for (int i = 1; i <= n; i++)//i�Ǹ��ڵ�
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
        //ѡ�����ڵ㣬Ȼ����ڵ�����������Ŀ+����������Ŀ=��ǰѡ����ڵ���ڵĶ�����������Ŀ
        int sum = 0;
        for (int i = 1; i <= n; i++)//i�Ǹ��ڵ�
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