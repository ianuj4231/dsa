class Solution {
public:
    int lengthOfLongestSubstring(string s) {
             unordered_set<char> set;
             int start=0, end=0;
             int maxx=0;
             while(start<s.size()){
                if(set.find(s[start])==set.end()){
                    maxx=max(maxx, start-end+1);
                    set.insert(s[start]);
                    start++;
                }
                else{
                    set.erase(s[end]);
                    end++;
                }
             }
             return maxx;
    }
    
};
