class Solution {
public:
    int helper(int ind, int target, vector<int>& coins, vector<vector<int>>& dp){
        if (target == 0) return 1;
        
        if (ind == 0) {
            if (target % coins[0] == 0) return 1;
            return 0;
        }
        if (dp[ind][target] != -1) return dp[ind][target];
        
        int notTake = helper(ind - 1, target, coins, dp);
        
        int take = 0;
        if (coins[ind] <= target) {
            take = helper(ind, target - coins[ind], coins, dp);
        }
        
        return dp[ind][target] = take + notTake;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return helper(n - 1, amount, coins, dp);
    }
};