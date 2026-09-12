class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp[nums[i]]++;

            int x = nums[i];
            // Advance 'i' to the very last element of the current block
            while (i + 1 < n && nums[i + 1] == x) {
                i++;
            }
        }

        int count = 0;
        for (auto it : mpp) {
            if (it.second == 1) {
                count++;
            }
        }

        return count;
    }
};