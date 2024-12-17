class Solution {
public:

    map<pair<int, int>, bool> memo;

    bool ispal(int left, int right, const string& s) {
        if (memo.find({left, right}) != memo.end()) {
            return memo[{left, right}];
        }
        
        while (left < right) {
            if (s[left] != s[right]) {
                memo[{left, right}] = false;
                return false;
            }
            left++;
            right--;
        }
        
        memo[{left, right}] = true;
        return true;
    }

    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<string>> res;
        vector<string> curr;
        bt(res, curr, n, s, 0);
        return res;
    }
    
    void bt(vector<vector<string>>& res, vector<string>& curr, int n, const string& s, int index) {
        if (index == s.size()) {
            res.push_back(curr);
            return;
        }
        for (int i = index; i < n; i++) {
            if (ispal(index, i, s)) {
                curr.push_back(s.substr(index, i - index + 1));
                bt(res, curr, n, s, i + 1);
                curr.pop_back();
            }
        }
    }
};
