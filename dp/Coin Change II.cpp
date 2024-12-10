class Solution {
public:
    int change(int amount, vector<int>& coins) {
     vector<int> dp( amount+1, 0);
     dp[0]=1;
     for(int coin: coins) {
     for(int i=1;i<=amount;i++){
          if(i>=coin) dp[i]= dp[i]+ dp[i- coin];
     }
    }
    return dp[amount];  
    }
};

/*


1 2 - coins 
3   - amount
0 1 2 3  dp array
1 1 2 2  no of ways
//////////////////////////
i will be the amount
if(coin<=i)
dp[1]= dp[1]+dp[1-1];
1        0 +    1 

to make amunt  of 2 using 1 rupee coin..  
dp[2]=dp[2]+ dp[2-1];
   1
        
dp[3]  = 1
///////////////////////////// 
use 2 rupees coin:
amt =1  xxxxx
if(coin<=i){
		amt 2  dp[2]+=dp[2-2] 
		amt 3  dp[3]=dp[3]+ dp[3-2]; 
				1 +  1
				2  
} 
return dp[amount];          8 using 3 and 5  ... no of ways is needed... 0 1  2 3 4 5 6  7  8
									 1 0  0 1 0 1 1  0  1
									to make 8 using 5,  we need 3 .. and no of ways to make 3 will be stored in an array called dp.



*/
