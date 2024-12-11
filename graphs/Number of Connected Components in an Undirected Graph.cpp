class Solution {
public:
    void dfs(int node, vector<vector<int>> &nums, vector<bool>&visited){
                visited[node]=true;
                for(int neighbour: nums[node]){
                      if(!visited[neighbour]){
                           dfs(neighbour, nums, visited);
                      }
                }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> nums(n, vector<int>(n,0));
            for(auto it: edges){
                   int first= it[0];
                  int second= it[1];
                  nums[first].push_back(second);
                  nums[second].push_back(first);
            }
            vector<bool> visited(n, false);
            int count=0;
            for(int i=0;i<n;i++){
                if(!visited[i]){
                                    count++;

                      dfs(i, nums, visited);
                }
            }
            return count;
    }
};
