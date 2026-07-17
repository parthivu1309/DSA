class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l = 0;
        int zero = 0;
        int r = 0;
        int maxlen = INT_MIN;

        while(r < nums.size() && l < nums.size()){

            if(nums[r] == 0) zero++;

            while(zero > k){
                if(nums[l] == 0) zero--;
                l++;
            }

            maxlen = max(r - l + 1,maxlen);
            r++;
        }

        return maxlen;
    }
};