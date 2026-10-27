class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long totalSum = 0;
        vector<int> gains;

        for (int num : nums) {
            totalSum += num; // Add the original number to our base sum
            
            // Convert to string to easily sort the digits descending
            string s = to_string(num);
            sort(s.rbegin(), s.rend());
            
            int maxNum = stoi(s); // Convert back to integer
            
            // Calculate how much extra sum we get by rearranging this number
            int gain = maxNum - num;
            if (gain > 0) {
                gains.push_back(gain);
            }
        }

        // Sort gains in descending order to pick the most profitable ones first
        sort(gains.rbegin(), gains.rend());

        // Add the top k gains (or fewer, if we run out of positive gains)
        for (int i = 0; i < k && i < gains.size(); i++) {
            totalSum += gains[i];
        }

        return totalSum;
    }
};