class Solution {
public:
    int smallestBalancedIndex(vector<int>& nums) {

        int n = nums.size();
        vector<long long> prefix(n);

        prefix[0] = nums[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        long long product = 1;

        for(int i = n-1; i >= 0; i--) {

            long long leftSum = (i == 0 ? 0 : prefix[i-1]);

            if(leftSum == product){
                return i;
            }
            if(product > (long long)1e14 / nums[i]) break;
            else{
               product *= nums[i];
            }
        }

        return -1;
    }
};