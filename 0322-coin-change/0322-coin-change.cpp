class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        // We only need a 1D array to track the previous row
        vector<int> prev(amount + 1, -1);
    
        // Base case for ind = 0
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0){
                prev[i] = i / coins[0];
            } else {
                prev[i] = 1e9;
            }
        }

        // Process remaining coins
        for(int i = 1; i < n; i++){
            // Create the current row array
            vector<int> curr(amount + 1, -1);
            
            // CRITICAL FIX: The base case for amount = 0 on the current row
            curr[0] = 0; 

            for(int j = 1; j <= amount; j++){
                
                int notTake = prev[j]; // Look at the row above
                int take = 1e9;

                // Look left on the CURRENT row
                if(coins[i] <= j){
                    take = curr[j - coins[i]] + 1; 
                }

                curr[j] = min(take, notTake);
            }
            // Move current row to previous row for the next iteration
            prev = curr;
        }
        
        if(prev[amount] >= 1e9) return -1;
        
        return prev[amount];
    }
};