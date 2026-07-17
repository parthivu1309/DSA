class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        // A 3D array to track visited points instantly (since coordinates are 0-6)
        bool visited[7][7][7] = {false};
        vector<vector<int>> all_points;
        vector<vector<int>> current_gen;

        // Edge case: check if target is already in the initial points
        for (const auto& p : points) {
            if (p == target) return 0;
            visited[p[0]][p[1]][p[2]] = true;
            all_points.push_back(p);
            current_gen.push_back(p);
        }

        int generation = 0;
        

        // Process generations using Breadth-First Search (BFS)
        while (!current_gen.empty()) {
            generation++;
            vector<vector<int>> next_gen;

            // Pair every newly generated point with ALL known points
            for (int i = 0; i < current_gen.size(); i++) {
                for (int j = 0; j < all_points.size(); j++) {
                    const auto& p1 = current_gen[i];
                    const auto& p2 = all_points[j];

                    // Points must be distinct
                    if (p1 != p2) {
                        // Integer division acts as floor for positive numbers
                        int nx = (p1[0] + p2[0]) / 2;
                        int ny = (p1[1] + p2[1]) / 2;
                        int nz = (p1[2] + p2[2]) / 2;

                        // Check if we hit the target
                        if (nx == target[0] && ny == target[1] && nz == target[2]) {
                            return generation;
                        }

                        // If it's a completely new point, save it for the next generation
                        if (!visited[nx][ny][nz]) {
                            visited[nx][ny][nz] = true;
                            next_gen.push_back({nx, ny, nz});
                        }
                    }
                }
            }

            // Append the newly found points to the master list
            for (const auto& p : next_gen) {
                all_points.push_back(p);
            }
            
            // Move to the next generation
            current_gen = next_gen;
        }

        // If no new points can be formed and target isn't found
        return -1; 
    }
};