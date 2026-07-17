class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1000000007;
        int n = nums.size();
        int q = queries.size();

        for(int i = 0; i < q; i++){
            int idx = queries[i][0];

            while(idx <= queries[i][1]){
                nums[idx] = (1LL * nums[idx] * queries[i][3]) % MOD;//why (1e9 + 7)?
                //answer is to prevent overflow
                idx += queries[i][2];
            }

        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans = ans^nums[i];
        }

        return ans;
    }
};