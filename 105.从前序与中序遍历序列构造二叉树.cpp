#include<iostream>
#include<vector>
using namespace std;

//  Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 //ǰ��-->������   ����-->������       ǰ�򶨸����ж�����
  //��ǰ��������ҵ����ڵ㣬Ȼ����������и��ݸ��ڵ�ֳ������������������������ڵ����Ŀ����ǰ������зֳ������������ݹ���ȥ
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int leftPreorder, int rightPreorder, int leftInorder, int rightInorder)
    {
        if (leftPreorder > rightPreorder)
            return NULL;
        else if (leftPreorder == rightPreorder)
        {
            TreeNode* newnode = new TreeNode(preorder[leftPreorder]);
            return newnode;
        }
        else
        {
            //�������ڵ���preorder[leftPreorder]   ��������
            TreeNode* rootnode = new TreeNode(preorder[leftPreorder]);
            int iterator = leftInorder;
            for (; iterator <= rightInorder; iterator++)
            {
                if (inorder[iterator] == preorder[leftPreorder])
                    break;
            }
            rootnode->left = buildTree(preorder, inorder, leftPreorder + 1, leftPreorder + iterator - leftInorder, leftInorder, iterator - 1);
            rootnode->right = buildTree(preorder,inorder, leftPreorder + 1 + iterator - leftInorder, rightPreorder, iterator+1, rightInorder);
            return rootnode;
        }
    }
};

/*int main()
{
    vector<int> pre = { 1,2 };
    vector<int> in = { 2,1 };
    Solution s1;
    s1.buildTree(pre, in);
}*/
