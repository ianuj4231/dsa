class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& nums) {
       int m=nums.size();
       int n=nums[0].size();
       int maxx=INT_MIN;
                   vector<vector<int> > memo(m, vector<int> (n , -1));
       function<int(int , int)> trav=[&](int x, int y)->int{
                 if(memo[x][y]!=-1){
                            return memo[x][y];
                        }
                int maxpath=1;
                vector<pair<int,int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
                for(auto xx:dirs){
                     int newx=x+xx.first;
                      int newy=y+xx.second;
                      if(newx>=0 && newy>=0 && newx<=m-1 && newy<=n-1 && nums[newx][newy]>nums[x][y]  ){
                                maxpath=max(maxpath, 1+trav(newx,newy));
                      }
                }
                return memo[x][y]= maxpath;

       };

       for(int i=0;i<m;i++){
        for(int j=0;j<n; j++){
               maxx=max(maxx, trav(i, j));
        }
       }
       return maxx;
    }
};
