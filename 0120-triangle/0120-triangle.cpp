class Solution {
public:
    int helper(vector<vector<int>>& triangle, int i, int j, vector<vector<int>>& dp) {
        int n = triangle.size();
        
        if (i == n - 1) return triangle[i][j];

        // Check against INT_MAX instead of -1
        if (dp[i][j] != INT_MAX) return dp[i][j];

        return dp[i][j] = triangle[i][j] + min(helper(triangle, i + 1, j, dp), 
                                               helper(triangle, i + 1, j + 1, dp));
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize with INT_MAX instead of -1
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return helper(triangle, 0, 0, dp);
    }
};