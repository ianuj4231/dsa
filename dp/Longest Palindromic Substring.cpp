#include <bits/stdc++.h>
using namespace std;

int main(){
                
string s =  "abbaccccc";
int n=s.size();
auto expandAroundCenter=[&](int left, int right)->int{
   
   while(left>=0 && right<=n-1 && s[left]==s[right]){
       left--;
       right++;
   }
   return right-left-1;
}; 

int maxx=0;
int start=0;
for(int i=0;i<n;i++){
     int len1=expandAroundCenter(i, i);
     int len2=expandAroundCenter(i, i+1);
      int curr=max(len1, len2)
;
     if(curr> maxx){
         maxx=curr;
         start=i-(curr-1) /2 ;
     }

}

cout<< s.substr(start, maxx);
  
}
