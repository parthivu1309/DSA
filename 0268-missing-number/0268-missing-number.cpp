class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            result ^= i ^ nums[i];
        }
        return result ^ nums.size();
    }
};
