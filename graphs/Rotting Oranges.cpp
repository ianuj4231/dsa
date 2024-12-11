class Solution {
public:
    int orangesRotting(vector<vector<int>>& nums) {
                int m=nums.size();
                int fresh=0;
                queue<pair<int, int>>q;
                int n=nums[0].size();
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                         if(nums[i][j]==2){
                                    q.push({i, j});
                         }  
                         else if(nums[i][j]==1){
                            fresh++;
                         }
                    }
                }
                        vector<pair<int, int>> dirs = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

                int mins=0;
                while(! q.empty() && fresh> 0 ){
                      int size=q.size();
                      bool isrotinthisround=false;
                       while(size--){
                               int i=q.front().first;
                               int j=q.front().second;
                               q.pop();
                                for(auto dir: dirs){
                                    int newi=i+dir.first;
                                    int newj=j+dir.second;
                                    if(newi >= 0 && newi < m && newj >= 0 && newj < n && nums[newi][newj]==1){
                                        nums[newi][newj]=2;
                                        isrotinthisround=true;
                                          q.push({newi, newj});
                                          fresh--;
                                    }
                                }
                       }
                       if(isrotinthisround){
                         mins++;
                       }
                }
                if(fresh>0){
                    return -1;
                }
                else{
                    return mins;
                }

    }
};

/*
Time Complexity:
The time complexity of this solution is O(m * n), where:

m is the number of rows in the grid.
n is the number of columns in the grid.
Explanation:
The while loop runs until either all fresh oranges are rotten or the queue becomes empty.
Each orange in the grid (either fresh or rotten) is processed at most once during the BFS. In the worst case, we visit every cell (m * n) and process it (check and potentially push it to the queue).
Therefore, the time complexity is O(m * n).
Space Complexity:
The space complexity is O(m * n) because:

The queue can store at most m * n elements in the worst case (if all cells are rotten or fresh and pushed to the queue).
Additionally, we maintain a constant number of variables for direction vectors and other control variables, so they do not add significant space complexity.
Thus, the space complexity is O(m * n), considering the storage of the grid and the queue.

Summary:
Time Complexity: O(m * n)
Space Complexity: O(m * n)






*/

