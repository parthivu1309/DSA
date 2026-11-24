class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int maxLen = 0;

        // Upper bound for (lcm * gcd) when all elements are in [1, 10]:
        // lcm(1..10) = 2520, max possible gcd = 10 -> 2520 * 10 = 25200.
        // Keeping prod capped near this value completely prevents integer overflow.
        const long long MAX_PRODUCT_BOUND = 25200;

        // Outer loop fixes the starting index 'i' of the subarray
        for (int i = 0; i < n; ++i) {
            long long curProd = 1;
            long long curGcd = 0;  // gcd(0, x) == x, making 0 the identity for GCD
            long long curLcm = 1;  // lcm(1, x) == x, making 1 the identity for LCM

            // Inner loop extends the subarray from 'i' to 'j'
            for (int j = i; j < n; ++j) {
                // Before this multiplication, curProd <= 25200 and nums[j] <= 10,
                // so the result is at most 252,000 (well within 32-bit/64-bit limits).
                curProd *= nums[j];

                // If the product already exceeds the maximum possible (lcm * gcd),
                // extending 'j' further will only keep curProd >= this value (since nums[k] >= 1),
                // so no longer subarray starting at 'i' can ever be valid.
                if (curProd > MAX_PRODUCT_BOUND) {
                    break;
                }

                // Incrementally update running GCD and LCM in O(log(min)) time
                curGcd = std::gcd(curGcd, (long long)nums[j]);
                curLcm = std::lcm(curLcm, (long long)nums[j]);

                // Check the product-equivalent condition
                if (curProd == curLcm * curGcd) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};