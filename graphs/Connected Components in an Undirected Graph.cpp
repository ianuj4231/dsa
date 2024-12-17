//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
  
  void dfs( vector<bool> &visited,int node,   vector<int> &curr,  vector<vector<int>> &listx){
        visited[node]=true;
        curr.push_back(node);
        for(int x: listx[node]){
             if(!visited[x])  dfs(visited, x, curr,  listx);
        }
}
  
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> listx(v);
        for(auto it: edges){
               int n1=it[0];
               int n2=it[1];
               listx[n1].push_back(n2);
               listx[n2].push_back(n1);
        }
          vector<vector<int>> res;
        int count=0;
        vector<bool>visited(v, false);
        for(int i=0;i<v;i++){
               if(!visited[i]){
                     vector<int> curr;
                     dfs(visited, i ,curr,  listx);
                     count++;
                      sort(curr.begin(), curr.end());
                     res.push_back(curr);
               }
        }
        return res;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
