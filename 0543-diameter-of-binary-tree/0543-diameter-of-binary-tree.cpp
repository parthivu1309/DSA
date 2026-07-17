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
    int maxDepth(TreeNode* root,int& diameter) {
        if(root == nullptr) return 0;

        int left = maxDepth(root->left,diameter);
        int right = maxDepth(root->right,diameter);

        diameter = max((left+right),diameter);

        int ans = max(left,right) + 1;

        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = INT_MIN;
        maxDepth(root,diameter);

        return diameter;
    }
};