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
    int maxPathSumHelper(TreeNode* root, int& maxSum) {
        // Base case: Null nodes contribute 0 to the path sum
        if (root == nullptr) return 0;

        // Recursively get the max path sum of the left and right subtrees.
        // If a subtree returns a negative sum, we ignore it by taking max(0, sum).
        int leftSum = max(0, maxPathSumHelper(root->left, maxSum));
        int rightSum = max(0, maxPathSumHelper(root->right, maxSum));

        // The maximum path sum passing through the CURRENT node (can include both branches)
        int currentMaxPath = root->val + leftSum + rightSum;
        
        // Update the global maximum if this is the best we've seen so far
        maxSum = max(maxSum, currentMaxPath);

        // For the parent node calling this function, it can only continue the path
        // through ONE of the children. So we return the node's value + the best single branch.
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN; // Initialize to the smallest possible integer
        maxPathSumHelper(root, maxSum);
        return maxSum;
    }
};