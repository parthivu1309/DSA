#include <bits/stdc++.h>
using namespace std;
//this header file is only for local testing and debugging, 
//it should be removed when submitting the code to leetcode

/*intution
In a rotated sorted array, 
the minimum element is the only element that is smaller than its previous*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        while (low < high) {  // Note: low < high, not low <= high
            int mid = low + (high - low) / 2;  // Calculate mid inside loop
            
            // If mid element is greater than rightmost element,
            // minimum must be in the right half
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            // Otherwise, minimum is in the left half (including mid)
            else {
                high = mid;
            }
        }
        
        return nums[low];  // Return the value, not the index
    }
};