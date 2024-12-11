class Solution {
public:

    void dfs(int &count, int i , int j, vector<vector<int>> &grid){
        int m=grid.size();
          int n=grid[0].size();

                if(i< 0 || j<0 || i> m-1 || j> n-1 || grid[i][j]==0){
                    return ;
                }
                grid[i][j]=0;
                count++;
                dfs(count, i+1, j, grid);
                  dfs(count, i, j+1, grid);
                    dfs(count, i, j-1, grid);
                      dfs(count, i-1, j, grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
          int m=grid.size();
          int n=grid[0].size();
          int maxx=0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                  if(grid[i][j]!=0){
                        int count=0;
                        dfs(count, i, j, grid);
                        maxx=max(maxx, count);
                  }
            }
          }
          return maxx;
    }
};
// time is O(m*n)
// space is .. O(m*n); what if it was fully filled with only 1's 
