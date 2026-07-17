class Solution {
public:

    int fun(vector<int>& nums, int k) {
        if(k < 0) return 0;//very important edge case

        int l = 0;
        int r = 0;
        int odd = 0;
        int ans = 0;

        while(r < nums.size()){

            if(nums[r] % 2 != 0) odd++;

            while(odd > k){
                if(nums[l] % 2 != 0) odd--;
                l++;
            }

            ans += (r - l + 1);
            r++;
        }

        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return fun(nums,k) - fun(nums,k-1);
    }
};