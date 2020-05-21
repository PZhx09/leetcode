#include<iostream>
#include<vector>
#include<queue>
using namespace std;



class Solution {
public:
    //�������� ÿ�ζ�ɾ��һ�����Ϊ0�ĵ�
    //����AC  ��һ�������ж��Ƿ��л�
    //��ʵ���������������
    /*
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int* inNode = new int[numCourses] {0};
        vector<int> ans;
        queue<int> inZeroNode;
        vector<vector<int>> edge;
        edge.resize(numCourses);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            //����ÿ��������
            inNode[prerequisites[i][0]]++;
            edge[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        //���������Ϊ0�ĵ�ӵ�������
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
            
            //�޸�����ڵ��ÿ�֮��Ӱ��Ľڵ����
            for (int i = 0; i < edge[node].size(); i++)//����ط�����һ���ÿռ任ʱ��   ����Ч�������ʱ�䣡����
            {
                 if (--inNode[edge[node][i]] == 0)
                     inZeroNode.push(edge[node][i]);
            }
        }
        if (ans.size() < numCourses)
            return vector<int>();
        return ans;

    }*/
    //�����������   ͦ����˼��   �������㿪ʼ   ������  ������ֳ�ȥ�ı߶���������  ��˵���������
    //���������������ɣ����ӣ���������������� ˵���л�

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<vector<int>> edge;
        edge.resize(numCourses);
        int* visited = new int[numCourses] {0}; //0δ������1�����У�2�������
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