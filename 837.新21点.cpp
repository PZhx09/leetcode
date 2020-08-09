#include<iostream>

using namespace std;

class Solution {
public:
    //牌的大小[1,W]  大于等于K时不可以抽牌   求分数小于等于N的概率
    //一点思路都没有，直接看题解

    //题解方法:动态规划
    //分解子问题:抽牌是否赢，只与开始时的分数有关   把整体问题，分解成每次抽卡
    //状态:dp[x]开始时为x，赢的概率
    //状态转移方程dp[x]=(dp[x+1]+...+dp[x+w])/w   这里想象一下概率分流
    //点数最大值是K-1+W     临界状态  大于min(N,K-1+W)之间胜率为0.          [k,min(N,K-1+W)]之间胜率为1    画个线段就能看明白了


    //超出时间限制
    //看看能不能通过减少计算次数来让它过去
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
            data -= dp[i + W];//利用自己的机灵过去了，哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈哈
        }
        return dp[0];
    }
};