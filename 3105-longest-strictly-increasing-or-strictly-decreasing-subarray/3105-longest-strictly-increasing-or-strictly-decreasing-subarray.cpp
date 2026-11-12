class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int incCount = 1;
        int decCount = 1;
        int maxCount = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                incCount++;
                decCount = 1; // Reset decreasing sequence
            } 
            else if (nums[i] < nums[i - 1]) {
                decCount++;
                incCount = 1; // Reset increasing sequence
            } 
            else {
                // Equal elements break both strict sequences
                incCount = 1;
                decCount = 1;
            }
            
            // The C++ initializer list allows max() to compare multiple values efficiently
            maxCount = max({maxCount, incCount, decCount});
        }
        
        return maxCount;
    }
};