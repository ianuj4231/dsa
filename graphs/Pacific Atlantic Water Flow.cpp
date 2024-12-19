class Solution {
public:

   void dfs(vector<vector<bool>> &ocean, int i,int j,vector<vector<int>> &nums){
                      int m=nums.size();
           int n=nums[0].size();

            ocean[i][j]=true;
            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            for(auto it:directions){
                              int ni = i + it.first, nj = j + it.second;
            if(ni >= 0 && ni < m && nj >= 0 && nj < n &&
                ocean[ni][nj]==false && nums[ni][nj] >= nums[i][j]){
                     dfs(ocean, ni, nj, nums);
                }
            }
   }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& nums) {
           int m=nums.size();
           int n=nums[0].size();
           vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

            for(int i=0;i<m;i++){
                  dfs(pacific, i, 0,  nums);
                  dfs(atlantic, i, n-1,  nums);
            }

            for(int j=0;j<n;j++){
                dfs(pacific, 0, j,  nums);
                dfs(atlantic, m-1, j,  nums);
            }

            for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                     if (pacific[i][j] && atlantic[i][j]) {
                    res.push_back({i, j});
                }
            }}
           return res;
    }
};
