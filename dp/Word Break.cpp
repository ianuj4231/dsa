#include <bits/stdc++.h>
using namespace std;

bool check(string s, map<string, bool> mp, int i, vector<int> dp ){
   if(s.size()==i){
     return true;
   }
   if(dp[i]!=-1)return dp[i];
   string sub="";
   for(int j=i;j<s.size();j++){
       sub+=s[j];
       if(mp.find(sub)!=mp.end() && check(s, mp, j+1, dp ) ){
           dp[i]=1;
           return true;
       }
   }
   dp[i]=0;
   return false;
}

int main(){
    vector<string   > nums={"sav", "efarmers" };
    string s="savefarmers";
    map<string, bool> mp;
    for(string x: nums){
         mp[x]= true;
    }
    vector<int> dp(s.size(), -1);
    cout <<  check( s, mp, 0, dp );
   
}
