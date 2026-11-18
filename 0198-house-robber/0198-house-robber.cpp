class Solution {
public:
    int helper(int i, vector<int>& nums, vector<int>& dp){
        int n = nums.size();
        //base cases
        if(i >= n)return 0;

        if(dp[i] != -1)return dp[i];

        int take = nums[i] + helper(i + 2, nums, dp);
        int notTake = helper(i + 1, nums, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();

        //dp[i] means constrain(max robbery amount) start from i ind
        vector<int>dp(n, -1);
        return helper(0, nums, dp);
    }
};