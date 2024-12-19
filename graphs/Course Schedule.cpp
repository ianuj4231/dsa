class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
               vector<vector<int>> graph(num);
               vector<int> indeg(num);
               for(auto it : prerequisites){
                  indeg[it[0]]++;
                  graph[it[1]].push_back(it[0]);
               }
               queue<int> q;
               for(
                int i=0;i<num;i++
               ) {
                  if(indeg[i]==0){
                       q.push(i);
                  }
               }
                int proc=0;
               while(! q.empty()){
                      int course=q.front();q.pop();
                                                    proc++;

                      for(int neigh : graph[course]){
                                indeg[neigh]--;
                                if(indeg[neigh]==0){
                                     q.push(neigh);
                                }
                      }
               }
               return  proc==num;
    }
};
