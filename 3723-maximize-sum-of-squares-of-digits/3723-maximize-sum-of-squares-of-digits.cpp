class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // If the target sum is larger than the maximum possible sum we can make 
        // with 'num' digits (which is all 9s), it's impossible.
        if (sum > num * 9) {
            return "";
        }
        
        string ans = "";
        
        // Greedily take the largest possible valid digit from left to right
        for(int i = 0; i < num; i++) {
            int take = min(9, sum);
            ans.push_back(take + '0');
            sum -= take;
        }
        
        return ans;
    }
};