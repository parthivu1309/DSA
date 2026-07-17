class Solution {
public:
    //function to findng all possibe ways from (m-1,n-1) to (0,0)
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);

        for(int i = 0; i < m; i++){
            vector<int>temp(n,0);
            for(int j = 0; j < n; j++){
                if(i == 0 && j == 0){
                    temp[j] = 1;

                    continue;
                }

                int up = 0;
                int left = 0;
                if(i > 0){
                    // up = dp[i-1][j];
                    up = prev[j];
                }
                if(j > 0){
                    // left = dp[i][j-1];
                    left = temp[j-1];
                }
                temp[j] = up + left;
            }
            prev = temp;
        }
        return prev[n-1];
    }
};