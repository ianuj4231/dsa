#include <bits/stdc++.h>
using namespace std;
    int maxProfit(const vector<int>& prices) {
        int n = prices.size();
        vector<int> buy(n);
        vector<int> cooldown(n);
        vector<int> sell(n);
        buy[0]=-prices[0];
        cooldown[0]=0;
        sell[0]=0;
        for(int i=1;i<n;i++){
              buy[i]=max(buy[i-1], cooldown[i-1 ]-prices[i]  );
  /* 
   //Either you keep the stock you bought earlier (buy[i-1]), or, Or, you were in the cooldown state (cooldown[i-1]), and now you buy the stock at the current price (- prices[i]).

  */
          sell[i]=buy[i-1]+ prices[i];
              cooldown[i]=max(cooldown[i-1 ], sell[i-1 ]);
            //sell on day i-1 and enter cooldown phase today or continue being in cooldown from day i-1 

        }
      return max(cooldown[n-1], sell[n-1 ]);
    }
int main(){
   cout<< maxProfit({5,3 , 9, 8 });
  
}
