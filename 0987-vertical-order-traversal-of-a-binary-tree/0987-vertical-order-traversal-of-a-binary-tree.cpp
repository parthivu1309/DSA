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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // A map is used to store nodes grouped by vertical and level
        map<int,map<int,multiset<int>>>nodes;
        // A queue is used for BFS, storing node and its coordinates
        queue<pair<TreeNode*,pair<int,int>>>q;

        q.push({root,{0,0}});
        
        //perform BFS Traversel
        while(!q.empty()){
            //extract node
            auto node = q.front();//very large data type
            q.pop();

            //extract vertical x
            int x = node.second.first;
            //extract level y
            int y = node.second.second;

            //insert nodes into the map by vertical and level 
            nodes[x][y].insert(node.first->val);

            //always push with updated coordinates;
            if(node.first->left) q.push({node.first->left,{x-1,y+1}});
            if(node.first->right) q.push({node.first->right,{x+1,y+1}});
        }

        vector<vector<int>>ans;

        //itrate through vertical in map
        for(auto level : nodes){
            vector<int>col;
            //collect all the nodes in the order of the level
            for(auto column : level.second){
                col.insert(col.end(),column.second.begin(),column.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};