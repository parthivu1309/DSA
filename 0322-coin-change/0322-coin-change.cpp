class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount + 1, -1));

        //base case for amt = 0;
        for(int i = 0; i < n; i++){
            dp[i][0] = 0;
        }
        //base case for ind = 0
        //When you are at i = 0 in your DP table, you are trying to make up the target amt using only the very first coin in your coins array (i.e., coins[0]).

        // Because you have an infinite supply of that single coin, you can only make the amount if it is perfectly divisible by the coin's denomination.

        // If it is divisible: The number of coins you need is simply the amount divided by the coin's value (amt / coins[0]).

        // If it is not divisible: You cannot form that amount with just this coin, so you store a very large number (like your 10e7) to represent infinity/impossible.
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                dp[0][i] = i / coins[0];
            }
            else{
                dp[0][i] = 1e9;
            }
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int take_update = 1e9;
                int take_notUpdate = 1e9;

                if(j - coins[i] >= 0){
                    take_update = dp[i - 1][j - coins[i]] + 1;
                    take_notUpdate = dp[i][j - coins[i]] + 1;
                }
                int notTake = dp[i-1][j];

                dp[i][j] = min(take_update, min(take_notUpdate, notTake));
            }
        }
        if(dp[n-1][amount] >= 1e9)return -1;
        else return dp[n-1][amount];
    }
};