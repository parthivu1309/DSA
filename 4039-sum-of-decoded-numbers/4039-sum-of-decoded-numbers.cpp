class Solution {
private:
    long long powerMod(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

public:
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        long long mod = 1e9 + 7;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            long long width = nums[i] % 10;
            long long d = nums[i] / 10;
            
            string s = to_string(d);
            
            // x takes the first 'width' digits; y takes the remaining digits
            long long x = stoll(s.substr(0, width));
            long long y = (width < s.size()) ? stoll(s.substr(width)) : 0;

            sum = (sum + powerMod(x, y, mod)) % mod;
        }

        return sum;
    }
};