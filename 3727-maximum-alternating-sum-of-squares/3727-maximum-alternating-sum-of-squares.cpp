class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        // Sort the array in descending order based on absolute values
        // so the largest potential squares are at the front.
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return abs(a) > abs(b);
        });
        
        long long sum = 0;
        int n = nums.size();
        
        // Number of elements that will be placed at even (added) indices
        int add_count = (n + 1) / 2; 
        
        for(int i = 0; i < n; i++) {
            long long square = (long long)nums[i] * nums[i];
            
            // Add the largest squares, subtract the smaller ones
            if(i < add_count) {
                sum += square;
            } else {
                sum -= square;
            }
        }
        
        return sum;
    }
};