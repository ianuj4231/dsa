class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res; // Stores the final result
        vector<string> curr;       // Stores the current partition
        backtrack(0, curr, res, s);
        return res;
    }

private:
    // Helper function to check if a substring is a palindrome
    bool ispalin(const string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Backtracking function
    void backtrack(int index, vector<string>& curr, vector<vector<string>>& res, const string& s) {
        if (index == s.size()) { // If the end of the string is reached
            res.push_back(curr); // Add the current partition to the result
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (ispalin(s, index, i)) { // Check if the substring is a palindrome
                curr.push_back(s.substr(index, i - index + 1)); // Add the substring
                backtrack(i + 1, curr, res, s);                 // Recursive call
                curr.pop_back();                               // Backtrack
            }
        }
    }
};
