class Solution {
public:
    int fun(int n){
        int maxi = INT_MIN;
        int mini = INT_MAX;

        while(n > 0){
            maxi = max(maxi, n % 10);
            mini = min(mini, n % 10);

            n /= 10;
        }
        return maxi - mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();

        vector<int>digit(n);
        int maxi = INT_MIN;
        for(int i = 0; i < n; i++){
            digit[i] = fun(nums[i]);
            
            maxi = max(maxi, digit[i]);
        }

        int sum = 0;
        for(int i = 0; i < n; i++){
            if(digit[i] == maxi){
                sum += nums[i];
            }
        }

        return sum;
    }
};