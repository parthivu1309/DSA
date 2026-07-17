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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        
        // Edge case: if the tree is empty, return the empty vector
        if (root == nullptr) {
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size(); // Number of nodes in the current level
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                // If this is the last node in the current level, add it to our answer
                if (i == levelSize - 1) {
                    ans.push_back(node->val);
                }
                
                // Push the next level's children into the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }
        
        return ans;
    }
};