class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = INT_MIN;

        vector<int> max_element(n);

        for(int i = 0; i < n; i++){
            if(i == 0)max_element[i] = nums[i];
            else{
                if(nums[i] > max_element[i - 1]) max_element[i] = nums[i];
                else max_element[i] = max_element[i - 1];
            }
        }

        for(int i = k; i < n; i++){
            maxi = max(maxi, nums[i] + max_element[i - k]);
        }

        return maxi;
    }
};