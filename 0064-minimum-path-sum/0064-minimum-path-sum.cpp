class Solution {
public:   
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> prev(n, 0);

        for(int i = 0; i < m; i++){
            vector<int> temp(n, 0);
            for(int j = 0; j < n; j++){
                // Base case: Top-left corner
                if(i == 0 && j == 0){
                    temp[j] = grid[i][j];
                    continue;
                }

                int up = 1e9;
                int left = 1e9;
                
                // Grab the cost from above (if valid)
                if(i > 0){
                    up = prev[j]; 
                }
                // Grab the cost from the left (if valid)
                if(j > 0){
                    left = temp[j-1]; 
                }
                
                // The new cost is the current cell's value PLUS the minimum of the previous paths
                temp[j] = grid[i][j] + min(up, left);
            }
            // Move the current row to be the "previous" row for the next iteration
            prev = temp;
        }
        return prev[n-1];
    }
};