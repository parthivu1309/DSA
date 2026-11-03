class Solution {
public:
    int minMoves(vector<int>& nums) {
        int count = 0;
        int max = *max_element(nums.begin(), nums.end());

        for(auto it : nums){
            count += (max - it);
        }

        return count;
    }
};