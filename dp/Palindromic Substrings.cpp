class Solution {
public:
    int countSubstrings(string s) {
        int ct=0;
        int n=s.size();
        auto exp=[&](int left, int right)->int{
             int ctx=0;
             while(left>=0 && right<=n-1 && s[left]==s[right]){
              left--;
              right++;
              ctx++;
        }
        return ctx;
       };
    
    for(int i=0;i<n;i++){
        ct+=exp(i,i);
        ct+=exp(i,i+1);
    }
    return ct;
    }
};
