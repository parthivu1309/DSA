class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix.size() - 1;

        if (matrix.empty() || matrix[0].empty()) return false;

        while(j >= i){
            int k = i + (j - i)/2;

            int low = 0;
            int high = matrix[k].size() - 1;

            if(matrix[k][high] < target) i = k + 1;
            else if(matrix[k][low] > target) j = k - 1;
            else{
                while(low <= high){
                    int mid = low + (high - low)/2;

                    if(matrix[k][mid] == target) return true;
                    else if(matrix[k][mid] > target) high = mid - 1;
                    else low = mid + 1;
                }
                return false;
            }
        }
        return false;
    }
};