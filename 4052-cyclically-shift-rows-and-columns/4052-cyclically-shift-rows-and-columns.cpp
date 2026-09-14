class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for(int i = 0; i < n; i++){
            vector<int>temp = grid[i];
            int k = rowShift[i];
            for(int j = 0; j < n; j++){
                grid[i][(j - k + n) % n] = temp[j];
            }
        }
        for(int i = 0; i < n; i++){
            vector<int>temp(n);
            for(int j = 0; j < n; j++){
                temp[j] = grid[j][i];
            }
            int k = colShift[i];
            for(int j = 0; j < n; j++){
                grid[(j - k + n) % n][i] = temp[j];
            }
        }
        return grid;
    }
};