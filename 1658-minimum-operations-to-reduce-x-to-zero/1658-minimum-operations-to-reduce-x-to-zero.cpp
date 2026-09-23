class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // Calculate the target sum for the middle subarray
        int target = accumulate(nums.begin(), nums.end(), 0) - x;
        
        // Edge cases
        if (target == 0) return nums.size(); // We need to remove all elements
        if (target < 0) return -1;           // x is strictly greater than the sum of all elements
        
        int max_len = -1;
        int current_sum = 0;
        int left = 0;
        
        // Sliding window to find the longest subarray with sum == target
        for (int right = 0; right < nums.size(); ++right) {
            current_sum += nums[right];
            
            // Shrink window from the left if the sum exceeds our target
            while (current_sum > target && left <= right) {
                current_sum -= nums[left];
                left++;
            }
            
            // If we found a valid subarray, track its maximum length
            if (current_sum == target) {
                max_len = max(max_len, right - left + 1);
            }
        }
        
        // Total elements minus the longest subarray length gives minimum operations
        return max_len != -1 ? nums.size() - max_len : -1;
    }
};