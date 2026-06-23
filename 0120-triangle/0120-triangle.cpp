class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m - 1].size();

        vector<vector<int>>dp(m,vector<int>(n,-1));

        vector<int>prev(n,-1);

        for(int i = 0; i < m; i++){
            vector<int>temp(n,-1);
            for(int j = 0; j <= i; j++){
                if(i == 0 && j == 0){
                    temp[j] = triangle[i][j];
                    continue;
                }
                int l = INT_MAX;
                int r = INT_MAX;

                if(i > j)
                l = prev[j];

                if(j > 0 && i > 0)
                r = prev[j-1];

                temp[j] = triangle[i][j] + min(l,r);
            }
            prev = temp;
        }

        int minPath = INT_MAX;
        for(int i = 0; i < m; i++){
            minPath = min(minPath, prev[i]);
        }

        return minPath;
    }
};