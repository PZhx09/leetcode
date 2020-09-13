#include<iostream>

using namespace std;

class Solution {
public:
    //�ƵĴ�С[1,W]  ���ڵ���Kʱ�����Գ���   �����С�ڵ���N�ĸ���
    //һ��˼·��û�У�ֱ�ӿ����

    //��ⷽ��:��̬�滮
    //�ֽ�������:�����Ƿ�Ӯ��ֻ�뿪ʼʱ�ķ����й�   ���������⣬�ֽ��ÿ�γ鿨
    //״̬:dp[x]��ʼʱΪx��Ӯ�ĸ���
    //״̬ת�Ʒ���dp[x]=(dp[x+1]+...+dp[x+w])/w   ��������һ�¸��ʷ���
    //�������ֵ��K-1+W     �ٽ�״̬  ����min(N,K-1+W)֮��ʤ��Ϊ0.          [k,min(N,K-1+W)]֮��ʤ��Ϊ1    �����߶ξ��ܿ�������


    //����ʱ������
    //�����ܲ���ͨ�����ټ��������������ȥ
    double new21Game(int N, int K, int W) {
        int max = K - 1 + W;
        if (max <= N)
            return 1;
        

        double* dp = new double[max + 1]{0};

        for (int i = K; i <= N && i <= max; i++)
            dp[i] = 1;
        double data = 0;
        for (int j = K; j <= K-1+W; j++)
        {
            data += dp[j];
        }
        for (int i = K - 1; i >= 0; i--)
        {
            dp[i] = data/W;
            data += dp[i];
            data -= dp[i + W];//�����Լ��Ļ����ȥ�ˣ���������������������������������������
        }
        return dp[0];
    }
};