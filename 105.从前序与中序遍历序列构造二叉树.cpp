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
 //前序-->中左右   中序-->左中右       前序定根，中定左右
  //从前序遍历中找到根节点，然后中序遍历中根据根节点分出左右子树，根据左右子树节点的数目，在前序遍历中分出左右子树，递归下去
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
            //子树根节点是preorder[leftPreorder]   根定左右
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
