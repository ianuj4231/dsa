/*
DFS Behavior:
From the treasure chest at (0, 2):

DFS might explore a long path first (e.g., down to (3, 2)) without exploring closer cells.
This would require additional checks to update the distance of already-visited cells if a shorter path is found.
Conclusion:
BFS is naturally suited for shortest-path problems like this, as it processes cells level by level. It avoids the need for additional checks and backtracking required by DFS, resulting in cleaner and more efficient code.
*/
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
            int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        // Enqueue all treasure chest positions (value 0)
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }
        while( ! q.empty()){
             auto[x, y]=q.front();
             q.pop();
              for (auto& dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == INT_MAX) {
                    grid[nx][ny] = grid[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
