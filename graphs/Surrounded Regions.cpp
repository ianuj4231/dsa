class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& nums){
             int m=nums.size();
           int n=nums[0].size();
            if(i<0|| j<0 || i>m-1 || j> n-1 || nums[i][j]=='T'||nums[i][j]=='X' )
            {
                return;
            }
            nums[i][j]='T';
            dfs(i, j+1, nums);
            dfs(i, j-1, nums);
            dfs(i+1, j, nums);
            dfs(i-1, j, nums);

    }

    void solve(vector<vector<char>>& nums) {
           int m=nums.size();
           int n=nums[0].size();
           
        //    0 j
        //    m-1 j

        //     i 0
        //     i n-1

            for(int i=0;i<m;i++){
                 if(nums[i][0]=='O')  dfs(i, 0, nums );
                  if(nums[i][n-1]=='O')  dfs(i, n-1, nums );
            }

              for(int j=0;j<n;j++){
                   if(nums[0][j]=='O') dfs(0,j,  nums );
                    if(nums[m-1][j]=='O') dfs( m-1, j, nums );
            }

            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                      if(nums[i][j]=='O'){
                                nums[i][j]='X';
                      }
                      else if(nums[i][j]=='T'){
                                nums[i][j]='O';
                      }
                }
            }
    }
};

/*
ok so if a middle O is connected to a border O vertically or horizontallu, then it must remain O

In the worst case, where all cells are 'O' and need to be marked as 'T', the DFS function could recurse through all cells. Therefore, the maximum depth of the recursion stack can be O(m * n) in the worst case.
O(m×n)
   is space adn time
*/

