#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v={1,5,10};
    int amount=12;
    vector<int>dp(amount+ 1, INT_MAX );
    dp[0]=0 ; min no of coins to make 0 is 0.
    // i means amount 
    for(int  i=1;i<=amount;i++){
         for(int coin: v ){
             if(coin<=i && dp[i-coin]!=INT_MAX ){
                 dp[i]=min(dp[i], 1+dp[i-coin]);
             }
         }
    }
    cout<<dp[amount];
    return 0;
}
