class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        //step- 1 prefixSum
        vector<int>prefixSum(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }

        //step-2 monotonic Deque
        deque<int>dq;
        int ans = INT_MAX;

        //process every prefix index
        for(int i = 0; i <= n; i++){
            //check valid subarray
            while(!dq.empty() && prefixSum[i] - prefixSum[dq.front()] >= target){
                ans = min(ans, i - dq.front());
                dq.pop_front();
            }

            //remove dominated prefix indexes
            while(!dq.empty() && prefixSum[i] <= prefixSum[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return ans == INT_MAX ? 0 : ans;
    }
};