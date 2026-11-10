class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        // Track the minimum cost to reach the previous 3 steps
        long long prev3 = INT_MAX; 
        long long prev2 = INT_MAX;
        long long prev1 = 0; // Starts at step 0 with cost 0
        
        for (int i = 1; i <= n; i++) {
            // Cost to jump to current step 'i' from i-1, i-2, and i-3
            long long cost1 = prev1 + costs[i - 1] + 1;
            long long cost2 = prev2 + costs[i - 1] + 4;
            long long cost3 = prev3 + costs[i - 1] + 9;
            
            // The optimal path to step i
            long long current = min({cost1, cost2, cost3});
            
            // Shift the state window forward for the next iteration
            prev3 = prev2;
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }
};