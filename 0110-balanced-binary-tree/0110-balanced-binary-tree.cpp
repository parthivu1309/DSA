/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left);
        int right = maxDepth(root->right);

        if(left == -1 || right == -1)  return -1;
        if(abs(left - right) > 1) return -1;

        int ans = max(left,right) + 1;

        return ans;
    }
    bool isBalanced(TreeNode* root) {
        int x = maxDepth(root);

        if(x == -1) return false;
        else return true;
    }
};