class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
          int m=grid.size();
          int n=grid[0].size();
          queue<pair<int, int>>q;
          int fresh=0;
          for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                        q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
          }
          int mins=0;
          vector<pair<int, int >>dirs={{0,1},{0,-1},{-1,0},{1,0}};
          while(!q.empty() ){
            bool isrotten=false;
            int sz=q.size();
            while(sz--  ){
                    int oldx = q.front().first;
                    int oldy = q.front().second;
                    q.pop();
                   for(int i=0;i<dirs.size();i++)
                   {
                        int newx=dirs[i].first+oldx;
                        int newy=dirs[i].second+oldy;
                        if(newx>=0 &&
                            newy>=0 &&
                            newx<=m-1 && 
                            newy<=n-1 &&
                         grid[newx][newy]==1){
                            grid[newx][newy]=2;
                            isrotten=true;
                              q.push({newx, newy});
                            fresh--;
                        }
                    }
            }
            if(isrotten){
                mins++;
            }
          }
          if(fresh==0){
            return mins;
          }
          else return -1;
    }
};
