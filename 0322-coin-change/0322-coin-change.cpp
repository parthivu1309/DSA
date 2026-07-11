class Solution {
public:
    int helper(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
        if(amt < 0) return 10e7;
        if(ind < 0) return 10e7;

        if(amt == 0) return 0;

        if(dp[ind][amt] != -1) return dp[ind][amt];

        int take_update = helper(ind-1, amt - coins[ind], coins, dp) + 1;
        int take_notUpdate = helper(ind, amt - coins[ind], coins, dp) + 1;
        int notTake = helper(ind-1, amt, coins, dp);

        return dp[ind][amt] = min(take_update, min(take_notUpdate, notTake));
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));
        if(helper(n-1, amount, coins, dp) >= 10e7) return -1;
        return helper(n-1, amount, coins, dp);
    }
};