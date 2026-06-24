class Solution {
public:
    bool helper(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return (nums[ind] == target);

        if(dp[ind][target] != -1)return dp[ind][target];

        bool take = false;
        if(target >= nums[ind]) take = helper(ind-1, target - nums[ind], nums, dp);

        bool notTake = helper(ind-1, target, nums, dp);

        return dp[ind][target] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }

        vector<vector<int>>dp(n, vector<int>(sum/2 + 1, -1));

        if(sum % 2) return false;
        else return helper(n-1, sum/2, nums, dp);
    }
};