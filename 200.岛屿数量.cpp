#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    //思路有问题
    //1  1  1
    //0  1  0
    //1  1  1
    //这种岛屿应该是1，但是这里结果是2

    //正确思路应该是dfs，上下左右。每到一个节点，如果是1，就置为0然后dfs   dfs的次数就是岛屿的次数
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
