class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        // If the sum is odd, we cannot divide it into two equal integer halves
        if(sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        // Changed to vector<bool> initialized to false for cleaner tabulation
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));
        
        // Base case 1: Target 0 is always achievable (empty subset)
        for(int i = 0; i < n; i++){
            dp[i][0] = true;
        }
        
        // Base case 2: First element can achieve a target equal to its value
        if(target >= nums[0]){
            dp[0][nums[0]] = true;
        }
        
        for(int i = 1; i < n; i++){
            for(int j = 1; j <= target; j++){

                bool take = false;
                if(j >= nums[i]) {
                    take = dp[i-1][j - nums[i]];
                }

                // FIX 1: Look at the previous row
                bool notTake = dp[i-1][j]; 
                
                // FIX 2: Store the result of (take OR notTake) into the current state
                dp[i][j] = take || notTake; 
            }
        }
        
        return dp[n-1][target];
    }
};