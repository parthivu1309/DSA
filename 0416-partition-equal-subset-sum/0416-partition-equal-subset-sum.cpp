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
        vector<bool>prev(target + 1, false);
        prev[0] = true;
        
        
        // Base case 2: First element can achieve a target equal to its value
        if(target >= nums[0]){
            prev[nums[0]] = true;
        }
        
        for(int i = 1; i < n; i++){
            vector<bool>curr(target + 1, false);
            curr[0] = true;
            for(int j = 1; j <= target; j++){

                bool take = false;
                if(j >= nums[i]) {
                    take = prev[j - nums[i]];
                }

                // FIX 1: Look at the previous row
                bool notTake = prev[j]; 
                
                // FIX 2: Store the result of (take OR notTake) into the current state
                curr[j] = take || notTake; 
            }
            prev = curr;
        }
        
        return prev[target];
    }
};