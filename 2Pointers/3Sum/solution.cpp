#include<bits/stdc++.h>
using namespace std;

// The Perfect $O(N^2)$ Strategy: "Fix One, Move Two"
// To correctly solve this in $O(N^2)$ time, we don't calculate mid. Instead, we iterate through the array, fixing one number at a time, and then use the standard two-pointer technique on the remaining right side of the array to find the other two numbers.
// Here is the standard, optimized approach:
// Sort the array: This takes $O(N \log N)$.
// Iterate with pointer i: Run a for loop from 0 to n-3. 
// This is our "fixed" number.
// Skip duplicates for i: If nums[i] == nums[i-1], continue to the next iteration to avoid duplicate triplets.
// Two Pointers (left and right): Set left = i + 1 and right = n - 1.
// Check the Sum: * If nums[i] + nums[left] + nums[right] == 0, you found a triplet! Add it to the answer. 
// Then, move both left and right inward, skipping any duplicates along the way.
// If the sum is < 0, we need a larger sum. Move left++.If the sum is > 0, we need a smaller sum. Move right--.


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Fix the first element (i) and find the other two
        for (int i = 0; i < n - 2; i++) {
            
            // Skip duplicate elements for the fixed pointer to avoid duplicate triplets
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            // Step 3: Standard two-pointer search
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    // Found a valid triplet
                    ans.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for the left pointer
                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    // Skip duplicates for the right pointer
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }
                    
                    // Move both pointers inward to look for new pairs
                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    // Sum is too small, we need a larger value
                    left++;
                } 
                else {
                    // Sum is too large, we need a smaller value
                    right--;
                }
            }
        }
        return ans;
    }
};