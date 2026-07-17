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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        int flag = 1;
        // 1. Handle the base case immediately
        if (root == nullptr) {
            return result; 
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            // Get the number of nodes at the current level
            int levelSize = q.size();
            
            // Temporary vector to hold the values of the current level
            vector<int> currentLevel;
            
            // Process all nodes for this exact level
            for (int i = 0; i < levelSize; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                currentLevel.push_back(temp->val);
                
                // Add children to the queue for the next level
                if (temp->left != nullptr) {
                    q.push(temp->left);
                }
                if (temp->right != nullptr) {
                    q.push(temp->right);
                }
            }
            
            // Push the completed level into our final 2D vector
            if(flag == 1){
                result.push_back(currentLevel);
                flag = 0;
            }
            else{
                reverse(currentLevel.begin(),currentLevel.end());
                result.push_back(currentLevel);
                flag = 1;
            }
        }

        return result;
    }
};