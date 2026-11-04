#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> costs(n, 0);
        
        priority_queue<pair<long long, int>> left; 
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> right; 
        
        vector<bool> in_left(n, false);
        long long sumL = 0, sumR = 0;
        int sizeL = 0, sizeR = 0;
        
        auto clean_tops = [&](int limit_idx) {
            while (!left.empty() && left.top().second <= limit_idx) {
                left.pop();
            }
            while (!right.empty() && right.top().second <= limit_idx) {
                right.pop();
            }
        };
        
        // Phase 1 & 2: Sliding Window using Lazy Deletion Heaps
        for (int i = 0; i < n; ++i) {
            // 1. Logically remove the element falling out of the window
            if (i >= x) {
                int rem_idx = i - x;
                if (in_left[rem_idx]) {
                    sumL -= nums[rem_idx];
                    sizeL--;
                } else {
                    sumR -= nums[rem_idx];
                    sizeR--;
                }
            }
            
            // 2. Insert the new incoming element safely
            clean_tops(i - x);
            if (sizeL > 0 && nums[i] <= left.top().first) {
                left.push({nums[i], i});
                in_left[i] = true;
                sumL += nums[i];
                sizeL++;
            } else {
                // When in doubt (or if left is empty), push to right.
                // The balance step will fix sizes automatically.
                right.push({nums[i], i});
                in_left[i] = false;
                sumR += nums[i];
                sizeR++;
            }
            
            // 3. Rebalance logical sizes based on the CURRENT window size
            int curr_req_left = (sizeL + sizeR + 1) / 2;
            
            while (sizeL > curr_req_left) {
                clean_tops(i - x);
                auto p = left.top();
                left.pop();
                sumL -= p.first;
                sizeL--;
                
                sumR += p.first;
                sizeR++;
                right.push(p);
                in_left[p.second] = false;
            }
            
            while (sizeL < curr_req_left) {
                clean_tops(i - x);
                auto p = right.top();
                right.pop();
                sumR -= p.first;
                sizeR--;
                
                sumL += p.first;
                sizeL++;
                left.push(p);
                in_left[p.second] = true;
            }
            
            // 4. Calculate equalizing cost when window size hits 'x'
            if (i >= x - 1) {
                clean_tops(i - x); 
                if (x % 2 == 0) {
                    costs[i] = sumR - sumL;
                } else {
                    costs[i] = sumR - sumL + left.top().first;
                }
            }
        }
        
        // Phase 3: Dynamic Programming
        const long long INF = 1e18; 
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, INF));
        
        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i][j] = dp[i - 1][j]; 
                
                if (i >= x && dp[i - x][j - 1] != INF) {
                    dp[i][j] = min(dp[i][j], dp[i - x][j - 1] + costs[i - 1]);
                }
            }
        }
        
        return dp[n][k];
    }
};