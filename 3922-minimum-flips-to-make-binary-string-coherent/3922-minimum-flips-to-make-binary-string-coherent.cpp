class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if (n < 3) return 0;

        int total_ones = 0;
        for (char c : s) {
            if (c == '1') total_ones++;
        }

        int total_zeros = n - total_ones;

        // Option 1: Convert to a string with at most one '1'
        // If there are no 1s, cost is 0. Otherwise, keep one '1' and flip the rest.
        int cost_one_or_less = (total_ones == 0) ? 0 : (total_ones - 1);

        // Option 2: Convert to a string with all '1's
        int cost_all_ones = total_zeros;

        // Option 3: Convert to the pattern "100...001"
        // This requires s[0] to be '1', s[n-1] to be '1', and all middle chars to be '0'.
        int cost_ends_ones = 0;
        
        // Check if we need to flip the ends to '1'
        if (s[0] == '0') cost_ends_ones++;
        if (s[n-1] == '0') cost_ends_ones++;
        
        // The middle elements should all be '0'. 
        // The number of '1's currently in the middle is:
        // total_ones - (is the first char '1'?) - (is the last char '1'?)
        int middle_ones = total_ones;
        if (s[0] == '1') middle_ones--;
        if (s[n-1] == '1') middle_ones--;
        
        // Add the cost of flipping middle '1's to '0's
        cost_ends_ones += middle_ones;

        // Return the absolute minimum of the valid states
        return min({cost_one_or_less, cost_all_ones, cost_ends_ones});
    }
};