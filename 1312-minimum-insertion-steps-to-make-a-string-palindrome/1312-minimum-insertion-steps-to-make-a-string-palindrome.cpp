class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // n x n table initialized to 0. 
        // 0 handles our "out of bounds / i > j" base cases automatically!
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // i goes backwards because dp[i] depends on dp[i+1]
        for (int i = n - 1; i >= 0; i--) {
            dp[i][i] = 1; // Base case: every single character is a palindrome of length 1
            
            // j goes forwards, starting right after i
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = 2 + dp[i+1][j-1];
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        // The answer for the whole string from index 0 to n-1
        return dp[0][n-1]; 
    }
    int minInsertions(string s) {
        int n = s.size();
        int x = longestPalindromeSubseq(s);

        return n - x;
    }
};