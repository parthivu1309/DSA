class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int sum = 0;
        int ans = INT_MAX;

        while(i < n && j < n){
            sum += nums[j];

            while(sum >= target){
                ans = min(ans, j - i + 1);
                sum -= nums[i++];
            }
            j++;
            
        }
        return ans == INT_MAX ? 0 : ans;
    }
};