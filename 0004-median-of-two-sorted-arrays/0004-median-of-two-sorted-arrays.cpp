class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> nums3(nums1.size() + nums2.size());

        merge(nums1.begin(), nums1.end(),nums2.begin(), nums2.end(),nums3.begin());

        int n = nums3.size();

        if (n % 2 != 0) {
            return nums3[n / 2];
        } else {
            return (nums3[n / 2] + nums3[n / 2 - 1]) / 2.0;
        }
    }
};