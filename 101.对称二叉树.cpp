#include<iostream>
#include<queue>
using namespace std;
 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    //递归方法
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
       // return isSymmetric(root->left, root->right);
        return check(root, root);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left != NULL && right != NULL)
        {
            if (left->val != right->val)
                return false;
            return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
        }
        else
            return false;

    }
    bool check(TreeNode* left, TreeNode* right)
    {
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(left);
        nodeQueue.push(right);

        while (!nodeQueue.empty())
        {
            TreeNode* l = nodeQueue.front();
            nodeQueue.pop();
            TreeNode* r = nodeQueue.front();
            nodeQueue.pop();
            if (l == NULL && r == NULL)
                continue;
            if (l != NULL && r != NULL)
            {
                if (l->val != r->val)
                    return false;

                nodeQueue.push(l->left);
                nodeQueue.push(r->right);

                nodeQueue.push(l->right);
                nodeQueue.push(r->left);
            }
            else
                return false;
        }
        return true;
    }

    //递归转迭代，经常需要使用一个队列！！！！
};