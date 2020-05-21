#include<iostream>
#include<vector>
#include<set>
using namespace std;


//这道题最初是想着使用set，但是后来发现没必要
//这道题可以引申二分图最大匹配的问题，匈牙利算法，不过这道题没这么复杂
//0和1分别代表一个不同的集合好了
//dfs和bfs应该都可以完成     先用dfs试试   dfs写起来麻烦，但是想的话，思路比较清晰
//bfs在实际写的时候，发现了一些问题
//自己对广度优先搜索和宽度优先搜索，理解不对
//本以为dfs是递归，bfs只是遍历
//但实质上，dfs和bfs都要递归，只是形式不一样
//以后做题，要想到用bfs或者dfs
//1.dfs和bfs都是递归方法
//2.dfs和bfs要设置好推出条件
/*class Solution {
public:
    bool dfs(int beginnode, int classify,int* color,vector<vector<int>>& graph)
    {
        for(int i = 0; i < graph[beginnode].size(); i++)
        {
            if (color[graph[beginnode][i]] == classify)
                return false;
            if (color[graph[beginnode][i]] == 1-classify)
                continue;
            color[graph[beginnode][i]] = 1 - classify;
            if (!dfs(graph[beginnode][i], 1 - classify, color, graph))
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int* color=new int[graph.size()];
        for (int i = 0; i < graph.size(); i++)
        {
            if (color[i]!=0&& color[i] != 1)
            {
                color[i] = 0;
                if (!dfs(i,0, color, graph))
                    return false;
            }

        }
        return true;


    }
};*/
class Solution {
public:
    bool bfs(int beginnode, int* color, vector<vector<int>>& graph)
    {
        if (color[beginnode] != 0&& color[beginnode] !=1)
        {
            color[beginnode] = 0;
        }
        vector<int> bfsarray;
        for (int i = 0; i < graph[beginnode].size(); i++)
        {
            if (color[graph[beginnode][i]] == color[beginnode])
                return false;
            if (color[graph[beginnode][i]] != 0 && color[graph[beginnode][i]] != 1)
                bfsarray.push_back(graph[beginnode][i]);
            color[graph[beginnode][i]] = 1 - color[beginnode];
        }
        for (int i = 0; i < bfsarray.size(); i++)
        {
            if (!bfs(bfsarray[i], color, graph))
                return false;
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int* color = new int[graph.size()];
        for (int i = 0; i < graph.size(); i++)
        {
            if (!bfs(i, color, graph))
                return false;
        }
        return true;

    }
};
/*int main()
{
    Solution s;
    vector <vector<int>> test1 = { {3},{2, 4},{1},{0, 4} ,{1,3} };//[[1],[0,3],[3],[1,2]]
    cout << s.isBipartite(test1);
}*/