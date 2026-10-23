#include <vector>

using namespace std;

class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i = 0, j = 0;

        while (true) {
            char dir = grid[i][j];
            grid[i][j] = '#'; // Mark the current cell as visited

            int ni = i;
            int nj = j;

            if (dir == 'R') nj++;
            else if (dir == 'L') nj--;
            else if (dir == 'U') ni--;
            else if (dir == 'D') ni++;

            // Stop if moving out of bounds or into an already visited cell
            if (ni < 0 || ni >= n || nj < 0 || nj >= m || grid[ni][nj] == '#') {
                break;
            }

            i = ni;
            j = nj;
        }

        return {i, j};
    }
};