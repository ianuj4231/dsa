class Solution {
public:
    bool checkInclusion(string s1, string s2) {
            vector<int> mp1(26, 0);
            vector<int> mp2(26, 0);   
             if (s1.size() > s2.size()) return false;        
            for(int i=0;i<s1.size();i++){
            mp1[s1[i]-'a']++;
            mp2[s2[i]-'a']++;
          }
          if(mp1==mp2){
                return true;
          }
         for(int i=s1.size();i<s2.size();i++){
                mp2[s2[i]-'a']++;
                mp2[s2[i-s1.size()]-'a']--;
                if(mp1==mp2){
                    return true;
                }
         }
         return false;
         
    }
};
