class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
            map<string, vector<string>> mp;
            vector<vector<string>> res;
            for(string str: strs){
                string strt=str;
                 sort(strt.begin(), strt.end());
                 mp[strt].push_back(str);
            }
            for(auto it: mp){
               
                res.push_back(it.second);
            }
            return res;
    }
};
