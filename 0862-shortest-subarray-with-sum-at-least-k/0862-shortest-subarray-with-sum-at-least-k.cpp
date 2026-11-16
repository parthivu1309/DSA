class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        // Step 1: Prefix Sum
        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        // Step 2: Monotonic Deque
        deque<int> dq;

        int ans = INT_MAX;

        // Step 3: Process every prefix index
        for(int i = 0; i <= n; i++) {

            // Check valid subarrays
            while(!dq.empty() &&
                  prefix[i] - prefix[dq.front()] >= k) {

                ans = min(ans, i - dq.front());

                dq.pop_front();
            }

            // Remove dominated prefix indices
            while(!dq.empty() &&
                  prefix[i] <= prefix[dq.back()]) {

                dq.pop_back();
            }

            // Insert current index
            dq.push_back(i);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};