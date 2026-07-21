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
    int count = 0;//global variable

    int Dominate(TreeNode* root){
        if(root == nullptr)return 0;

        int left = 0;
        int right = 0;
        
        if(root->left){
            left = Dominate(root->left);
        }
        if(root->right){
            right = Dominate(root->right);
        }

        int maxi = max(left,right);
        if(root->val >= left && root->val >= right)count++;

        return max(maxi,root->val);
    }
    int countDominantNodes(TreeNode* root) {
        Dominate(root);

        return count;
    }
};