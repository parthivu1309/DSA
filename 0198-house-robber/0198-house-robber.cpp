
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 0) return 0;
        if(n == 1) return nums[0];

        int prev2 = 0;
        int prev1 = 0;
        int curr;

        // Base cases
        prev1 = nums[0];

        // Build the DP table
        for(int i = 1; i < n; i++) {

            int take = nums[i];

            if(i >= 2) {
                take += prev2;
            }

            int notTake = prev1;

            curr = max(take, notTake);

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
