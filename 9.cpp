#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    //��������뷨����ʵ�Ͱ�����ת����stringûʲô����
    /*bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x < 10)
            return true;
        vector<int> data;
        while (x>0)
        {
            data.push_back(x % 10);
            x = (x - data.back())/10;
        }
        for (int j = 0; j < data.size()/2; j++)
        {
            if (data[j] != data[data.size() - j - 1])
                return false;
        }
        return true;
    }*/
    //��Ȼ�ǻ���������ô��תǰ��Ӧ����ȡ�����Ҫ����һ������������int��Խ��
    bool isPalindrome(int x) 
    {
        if (x < 0)
            return false;
        int origin = x;
        long long res = 0;
        while (x)
        {
            res = res * 10 + x % 10;
            x = x / 10;
        }
        return res == origin;
        
    }
};

/*int main()
{
    Solution s1;
    cout<<s1.isPalindrome(123)<<endl;
}*/