#include<iostream>
#include<vector>
#include<queue>

using namespace std;
  //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        int numlevel = 1;  //记录每一层有多少的节点数目
        while (!nodeQueue.empty())  //一次while循环，搞定一层
        {
            vector<int> thisLevel;
            int nextLevel = 0;
            for (int i = 0; i < numlevel; i++)
            {
                TreeNode* tmp = nodeQueue.front();
                nodeQueue.pop();
                thisLevel.push_back(tmp->val);
                if (tmp->left != NULL)
                {
                    nextLevel++;
                    nodeQueue.push(tmp->left);
                }
                if (tmp->right != NULL)
                {
                    nextLevel++;
                    nodeQueue.push(tmp->right);
                }

            }
            numlevel = nextLevel;
            ans.push_back(thisLevel);

        }
        return ans;
    }
};

/*int main()
{
    Solution s1;
    TreeNode* root = new TreeNode(3);
    TreeNode* test9   = new TreeNode(9);
    TreeNode* test20 = new TreeNode(20);
    root->left = test9;
    root->right = test20;
    s1.levelOrder(root);
}*/