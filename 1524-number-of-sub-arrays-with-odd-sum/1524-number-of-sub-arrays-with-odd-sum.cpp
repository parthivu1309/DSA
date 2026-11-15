
class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    long long solve(int i, vector<int>& arr, int parity) {
        if (i < 0) return 0;

        if (dp[i][parity] != -1)
            return dp[i][parity];

        long long odd, even;

        odd = solve(i - 1, arr, 1);
        even = solve(i - 1, arr, 0);

        if (arr[i] % 2 != 0) {
            odd = even + 1;
            even = solve(i - 1, arr, 1);
        }
        else {
            even = even + 1;
        }

        return dp[i][parity] = (parity == 1 ? odd : even) % MOD;
    }

    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        dp.assign(n, vector<long long>(2, -1));

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = (ans + solve(i, arr, 1)) % MOD;
        }

        return ans;
    }
};
