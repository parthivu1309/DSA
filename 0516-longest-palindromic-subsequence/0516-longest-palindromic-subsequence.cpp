class Solution {
public:
    int helper(int ind1, int ind2, string& s, vector<vector<int>>& dp){
        if(ind1 == ind2)return 1;//this might be doughtful
        if(ind1 > ind2)return 0;
        
        if(ind1 < 0 || ind2 < 0  || ind1 > s.size() - 1 || ind2 > s.size() - 1)return 0;

        if(dp[ind1][ind2] != -1)return dp[ind1][ind2];

        if(s[ind1] == s[ind2])
           return dp[ind1][ind2] = 2 + helper(ind1 + 1, ind2 - 1, s, dp);
        
        return dp[ind1][ind2] = max(helper(ind1+1, ind2, s, dp), helper(ind1, ind2-1, s, dp));
    }
    int longestPalindromeSubseq(string s) {
        int ind1 = 0;
        int ind2 = s.size();
        vector<vector<int>>dp(ind2, vector<int>(ind2, -1));

        return helper(ind1, ind2 - 1, s, dp);
    }
};