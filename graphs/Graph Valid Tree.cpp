/*
ok so false if either if disconnecte dor either if cyclci
ChatGPT said:
ChatGPT
Yes, exactly! A valid tree must satisfy two conditions:

No cycles: A tree cannot have any cycles. If there's a cycle, the graph is not a tree.

Connected: A tree must be connected. This means there must be exactly one path between any two nodes, and all nodes must be reachable from any other node. If the graph is disconnected (i.e., some nodes aren't connected by any path), then it's not a tree.
[[0,1],[ 2,3]  ]... (n/edges)=4..consider this test case.
So, to summarize:
If the graph has more than n - 1 edges, it's impossible to form a tree because it would necessarily contain a cycle.
If the graph has less than n - 1 edges, it's impossible to form a tree because it would be disconnected (some nodes won't have a path to others).
Both of these conditions must be checked, which is why we:
First check if the number of edges is exactly n - 1.
Then use union-find to check if adding an edge creates a cycle or if any nodes are disconnected.
If the graph has exactly n - 1 edges, and no cycles exist, and it's connected, the answer should be true.
*/

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
         
            vector<int> parent(n+1), rank(n+1,0);
                  if (edges.size() != n - 1) {
            return false;
        }
            for(int i=1;i<=n;i++){
                parent[i]=i;
            }
            for(auto it:edges){
                 int u=it[0];
                 int v=it[1];
                 if(findpar(u, parent)==findpar(v, parent)){
                    return false;
                 }
                 us(parent, rank, u, v);
            }
            return true;
    }

    int findpar(int node, vector<int> &parent ){
            if(parent[node]!=node){
                parent[node]= findpar( parent[node], parent );
            }
            return parent[node];
    }

    void us( vector<int>  &parent,  vector<int>  &rank, int u,int v){
        int rootu=findpar(u, parent);
        int rootv=findpar(v, parent);
        if(rootu!=rootv){
             if(rank[rootu]==rank[rootv]){
                parent[rootv]=rootu;
                rank[u]++;
             }
             else if(rank[rootu]>rank[rootv]){
                parent[rootv]=rootu;
             }
             else{
                parent[rootu]=rootv;
             }
        }
    }
};
