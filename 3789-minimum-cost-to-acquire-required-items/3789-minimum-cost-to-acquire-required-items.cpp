class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int n = min(need1, need2);
        long long ans = 0;
        
        // Simplified unit cost check avoids overflow entirely.
        // Cast to long long in case cost1 + cost2 exceeds INT_MAX
        if (1LL * cost1 + cost2 > costBoth) {
            ans += 1LL * costBoth * n;
        } else {
            ans += 1LL * cost1 * n + 1LL * cost2 * n;
        }

        if (need1 > n) {
            ans += 1LL * min(cost1, costBoth) * (need1 - n);
        } else {
            ans += 1LL * min(cost2, costBoth) * (need2 - n);
        }

        return ans;
    }
};