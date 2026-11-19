class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n = nums.size();
        //our ans should be lowScore + highScore
        //for minimizing ans we need to minimize both
        //lowScore mini can be 0 when two elements are same

        //for highScore check all 3 conditions

        sort(nums.begin(), nums.end());

        int ans = min(nums[n - 1] - nums[2], min(nums[n - 3] - nums[0], nums[n - 2] - nums[1]));

        return ans;
    }
};