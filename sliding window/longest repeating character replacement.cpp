class Solution {
public:
    int characterReplacement(string s, int k) {
            unordered_map<char, int>mp;
            int start=0, end=0;
            int maxx=0, maxfreq=0;
            while(start< s.size()){
                   mp[s[start]]++;
                   maxfreq=max(maxfreq, mp[s[start]]);
                   int windowsize=start-end+1;
                   // a a a b g , k =1 
                   if(windowsize> k + maxfreq ){
                                mp[s[end]]--;
                                end++;
                   }
                   windowsize=start-end+1;
                   start++;
                   maxx=max(windowsize, maxx);
            }
            return maxx;

}
};
