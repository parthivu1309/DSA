class Solution {
public:
    bool solve(int i, int j, int openCount, vector<vector<char>>& grid, vector<vector<vector<int>>>& t) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Process current cell's character
        openCount += (grid[i][j] == '(') ? 1 : -1;

        if(openCount < 0)
            return false;

        if(t[i][j][openCount] != -1) {
            return t[i][j][openCount];
        }
        
        // Reached destination
        if(i == m-1 && j == n-1)
            return t[i][j][openCount] = (openCount == 0);

        // move down
        if(i+1 < m) {
            // Passed 't' into the recursive call
            if(solve(i+1, j, openCount, grid, t)) 
                return t[i][j][openCount] = true;
        }

        // move right
        if(j+1 < n) {
            // Passed 't' into the recursive call
            if(solve(i, j+1, openCount, grid, t)) 
                return t[i][j][openCount] = true;
        }

        return t[i][j][openCount] = false;
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Mathematical pruning: Path length must be even, start with '(', end with ')'
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m-1][n-1] == '(') {
            return false;
        }

        int maxCount = m + n;

        // DP table initialized
        vector<vector<vector<int>>> t(m, vector<vector<int>>(n, vector<int>(maxCount, -1)));
        
        // Start at 0,0 with openCount 0 (it will be incremented to 1 instantly inside solve)
        return solve(0, 0, 0, grid, t);
    }
};