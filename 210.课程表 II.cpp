#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Solution {
public:
    //拓扑排序 每次都删除一个入度为0的点
    //两遍AC  第一次忘记判断是否有环
    //其实叫做宽度优先搜索
    /*
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int* inNode = new int[numCourses] {0};
        vector<int> ans;
        queue<int> inZeroNode;
        vector<vector<int>> edge;
        edge.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            //计算每个点的入度
            inNode[prerequisites[i][0]]++;
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //将所有入度为0的点加到队列中
        for (int i = 0; i < numCourses; i++)
        {
            if (inNode[i] == 0)
                inZeroNode.push(i);
        }
        while (!inZeroNode.empty())
        {
            int node = inZeroNode.front();
            inZeroNode.pop();
            ans.push_back(node);
            
            //修改这个节点拿开之后，影响的节点入度
            for (int i = 0; i < edge[node].size(); i++)//这个地方考虑一下用空间换时间   很有效的提高了时间！！！
            {
                 if (--inNode[edge[node][i]] == 0)
                     inZeroNode.push(edge[node][i]);
            }
        }
        if (ans.size() < numCourses)
            return vector<int>();
        return ans;

    }*/
    //深度优先搜索   挺有意思的   从任意结点开始   搜索中  如果发现出去的边都搜索过了  就说明搜索完成
    //如果碰到了搜索完成，无视，如果碰到了搜索中 说明有环

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> edge;
        edge.resize(numCourses);
        int* visited = new int[numCourses] {0}; //0未搜索，1搜索中，2搜索完成
        for (int i = 0; i < prerequisites.size(); i++)
        {
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        bool invalid = false;
        for (int i = 0; i < numCourses; i++)
        {
            if (visited[i] == 0)
                dfs(i, ans, edge, invalid, visited);
        }
        if (invalid)
            return {};

        reverse(ans.begin(), ans.end());
        return ans;

    }
    void dfs(int node, vector<int>& ans, vector<vector<int>>& edges, bool& invalid, int* visited)
    {
        visited[node] = 1;

        for (int i = 0; i < edges[node].size(); i++)
        {
            if (visited[edges[node][i]] == 0)
                dfs(edges[node][i],ans, edges, invalid, visited);
            else if (visited[edges[node][i]] == 1)
            {
                invalid = true;
                return;
            }


        }
        ans.push_back(node);
        visited[node] = 2;
        return;
    }
};

/*int main()
{
    Solution s1;
    vector<vector<int>> test = {{1, 0}, { 2, 1}};
    cout<<s1.findOrder(3, test)[0]<<endl;
}*/