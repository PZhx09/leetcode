#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //˼·������
    //1  1  1
    //0  1  0
    //1  1  1
    //���ֵ���Ӧ����1��������������2

    //��ȷ˼·Ӧ����dfs���������ҡ�ÿ��һ���ڵ㣬�����1������Ϊ0Ȼ��dfs   dfs�Ĵ������ǵ���Ĵ���
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != '0')
                {
                    int newIsland = true;
                    if (i > 0 && grid[i - 1][j] == '1')
                        newIsland = false;
                    if (j > 0 && grid[i ][j-1] == '1')
                        newIsland = false;
                    if (newIsland)
                        count++;
                }
            }
        }
        return count;
    }
};
