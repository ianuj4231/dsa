#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Base case: no input
        
        // Map digits to their corresponding letters
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> result;
        string current;
        
        // Start recursive backtracking
        backtrack(digits, 0, current, result, mapping);
        return result;
    }
    
private:
    void backtrack(const string &digits, int index, string &current, vector<string> &result, const vector<string> &mapping) {
        if (index == digits.size()) {
            // If all digits are processed, save the current combination
            result.push_back(current);
            return;
        }
        
        // Get the characters mapped to the current digit
        string letters = mapping[digits[index] - '0'];
        for (char letter : letters) {
            // Add the letter to the current combination
            current.push_back(letter);
            
            // Recur for the next digit
            backtrack(digits, index + 1, current, result, mapping);
            
            // Backtrack: remove the last added letter
            current.pop_back();
        }
    }
};

int main() {
    Solution sol;
    string digits = "34";
    vector<string> result = sol.letterCombinations(digits);
    
    for (const string &comb : result) {
        cout << comb << " ";
    }
    return 0;
}
