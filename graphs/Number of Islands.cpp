class Solution {
    private:

public:

    void dfs(int i, int j,vector<vector<char>>& grid ){
                    int m = grid.size();
                    int n = grid[0].size();
                    if(i<0||j<0||i>m-1||j>n-1||grid[i][j]=='0'){
                        return ;
                    }
                    grid[i][j]='0';
                    dfs(i+1, j, grid );
                    dfs(i-1, j, grid );
                    dfs(i, j-1, grid );
                    dfs(i, j+1, grid );

    }

    int numIslands(vector<vector<char>>& grid) {
      
            int ct= 0;
            int m = grid.size();
            int n  = grid[0].size();
             for(int i=0;i<m;i++){
                for(int j=0;j<n;++j){
                    if('1'==grid[i][j]){
                    dfs(i, j, grid );
                    ++ct;
             }
                }
             }
             return ct;
    }
};
