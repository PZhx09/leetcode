#include<iostream>
#include<vector>
#include<set>
using namespace std;


//��������������ʹ��set�����Ǻ�������û��Ҫ
//���������������ͼ���ƥ������⣬�������㷨�����������û��ô����
//0��1�ֱ����һ����ͬ�ļ��Ϻ���
//dfs��bfsӦ�ö��������     ����dfs����   dfsд�����鷳��������Ļ���˼·�Ƚ�����
//bfs��ʵ��д��ʱ�򣬷�����һЩ����
//�Լ��Թ�����������Ϳ��������������ⲻ��
//����Ϊdfs�ǵݹ飬bfsֻ�Ǳ���
//��ʵ���ϣ�dfs��bfs��Ҫ�ݹ飬ֻ����ʽ��һ��
//�Ժ����⣬Ҫ�뵽��bfs����dfs
//1.dfs��bfs���ǵݹ鷽��
//2.dfs��bfsҪ���ú��Ƴ�����
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