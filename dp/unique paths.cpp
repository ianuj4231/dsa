
#include <bits/stdc++.h>
using namespace std;
int findx(int m, int n ){
       vector<int> dp(n,   1);
       for(int i=1;i<m;i++){
         for(int j=1;j< n;j++ ){
           
             dp[j]=dp[j]+ dp[j-1];
         }
       }
       return dp[n-1];
}
int main(){
   
    int x=findx (3, 2);
      cout<< x<<endl; 
}


// #include <bits/stdc++.h>
// using namespace std;
// int findx(int m, int n ){
//     vector<vector<int>> dp(m, vector<int> (n, 0));
//     for(int i=0;i<m;i++){
//         dp[i][0]=1;
//     }
//     for(int j=0;j < n ;j++){
//         dp[0 ][j  ]=1;
//     }
//     for(int i=1;i<m;i++)
//     {
//       for(int j=1;j< n ;j++ ){
//           dp[i][j]=dp[i][j-1 ]+ dp[i-1][j];
//       }
//     }
//     return dp[m-1][n-1];
// }
// int main(){
   
//     int x=findx (3, 2);
//       cout<< x<<endl; 
// }


