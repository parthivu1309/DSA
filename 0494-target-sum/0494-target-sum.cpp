class Solution {
    int totalSum; // Store total sum to use as our offset
public:
    int helper(int ind, int target, vector<int>& nums, vector<vector<int>>& dp) {
        // Base Case
        if(ind == 0) {
            if(target - nums[ind] == 0 && target + nums[ind] == 0) return 2;
            if(target - nums[ind] == 0 || target + nums[ind] == 0) return 1;
            else return 0;
        }
        
        // Guard against mathematically impossible branches that exceed our bounds
        if(abs(target) > totalSum) return 0;

        // Apply the offset (target + totalSum) to ensure the index is always >= 0
        if(dp[ind][target + totalSum] != -1) return dp[ind][target + totalSum];
        
        int add = helper(ind-1, target - nums[ind], nums, dp);
        int sub = helper(ind-1, target + nums[ind], nums, dp);

        return dp[ind][target + totalSum] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        
        totalSum = 0;
        for(int num : nums) totalSum += num;
        
        // Edge case: If the initial target is completely out of reach
        if (abs(target) > totalSum) return 0;

        // DP table dimension: n rows, (2 * totalSum + 1) columns
        // This covers everything from -totalSum to +totalSum
        vector<vector<int>> dp(n, vector<int>(2 * totalSum + 1, -1));
        
        return helper(n-1, target, nums, dp);
    }
};