#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
                int n=edges.size();
                vector<int>parent(n+1);
                vector<int>rank(n+1, 0);
                for(int i=1;i<=n;i++){
                        parent[i]=i;
                }
                for(auto it: edges){
                      int u=it[0];
                      int v=it[1];
                      if(findparent(parent, u)==findparent(parent, v)){
                        return {u,v};
                      }
                      us(parent, rank, u,v);
                }
    }
    int findparent(vector<int>& parent , int node){
            if(parent[node]!=node){
                 parent[node]=findparent(parent,parent[node]);
            }
            return parent[node];
    }

    void us(vector<int>& parent, vector<int>& rank, int u, int v) {
            int rootu= findparent(parent, u);
        int rootv = findparent(parent, v);
            if(rank[rootu]==rank[rootv]){
                    parent[rootv]=rootu;
                    rank[rootu]++;
            }
            else if(rank[rootu]>rank[rootv]){
                parent[rootv]=rootu;
            }
            else{
                parent[rootu]=rootv;
            }
    }
};
