// class Solution {
// public:
//     int numDistinct(string s, string t) {
//           int m =s.size();
//           int n=t.size();
//             vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
//             for(int i=0;i<=m;i++){
//                             dp[i][0]=1;
//             }
//             for(int i=1;i<=m;i++){
//                 for(int j=1;j<=n;j++){
//                       if(s[i-1]==t[j-1]){
//                             dp[i][j]=dp[i-1][j]+dp[i-1][j-1];
//                       }
//                       else{
//                             dp[i][j]=dp[i-1][j];
//                       }
//                 }
//             }
//             return dp[m][n];
//      }
// };
////////////////////////////////////////////////////////////////////////////////////////////


class Solution {
public:
    int numDistinct(string s, string t) {
          int m =s.size();
          int n=t.size();
                vector<int>prev(n+1, 0);
                        vector<int>curr(n+1, 0);
                        prev[0]=1;
            for(int i=1;i<=m;i++){
                curr[0]=1;
                for(int j=1;j<=n;j++){
                      if(s[i-1]==t[j-1]){
                            curr[j]=prev[j]+prev[j-1];
                      }
                      else{
                            curr[j]=prev[j];
                      }
                }
                      prev=curr;
            }
            return prev[n];
     }
};

