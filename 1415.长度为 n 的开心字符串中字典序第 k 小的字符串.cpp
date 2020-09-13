#include<iostream>
#include<string>
#include<vector>
using namespace std;


class Solution {
public:
    //��һ���뷨��ȫ���У��г���Ȼ�󷵻ص�k��
    //���������Ȼʱ�临�ӶȺͿռ临�Ӷȶ�����

    //����kֱ�Ӷ�λ
    //�������ע�⵽k-1�����⣬��Ϊ���ﲻ�Ǵ�0��ʼ�ģ�������������⣬��ô���翪ʼ��k-1������0��ʼ
    //ע��� 1�� k-1  ��0��ʼ
    //2��base�ı仯
    /*string getHappyString(int n, int k) {
        string ans;
        if (k < 0 || k>3 * pow(2, n - 1))
            return "";
        int base = pow(2, n - 1);
        k=k - 1;
        ans += 'a' + k / base;
        k = k % base;
        base=base >> 1;
        n--;
        char last = ans[0];
        
        while (n)
        {
            int tmp = k / base;
            switch (last)
            {
            case 'a':
                if (tmp)
                {
                    ans += 'c';
                    last = 'c';
                }
                else
                {
                    ans += 'b';
                    last = 'b';
                }
                break;
            case 'b':
                if (tmp)
                {
                    ans += 'c';
                    last = 'c';
                }
                else
                {
                    ans += 'a';
                    last = 'a';
                }
                break;
            case 'c':
                if (tmp)
                {
                    ans += 'b';
                    last = 'b';
                }
                else
                {
                    ans += 'a';
                    last = 'a';
                }
                break;
            }
            n--;
            k = k % base;
            base = base >> 1;
        }
        return ans;
    }*/
    //д���Ͻ����Ż�
    string getHappyString(int n, int k) {
        string ans;
        if (k < 0 || k>3 * pow(2, n - 1))
            return "";
        int base = pow(2, n - 1);
        k = k - 1;
        ans += 'a' + k / base;
        k = k % base;
        base = base >> 1;
        n--;
        char last = ans[0];
        vector <vector<char>> data= { {'b', 'c'}, { 'a','c' }, { 'a','b' }};


        while (n)
        {
            int tmp = k / base;
            ans += data[last - 'a'][tmp];
            last = data[last - 'a'][tmp];
            n--;
            k = k % base;
            base = base >> 1;
        }
        return ans;
    }
};
/*int main()
{
    Solution s1;
   cout<< s1.getHappyString(7, 8);
}*/
