class Solution {
public:
   int countSubstrings(string s) {
    int n = s.length();
    int count = 0;

    // Helper lambda function to expand around the center
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < n && s[left] == s[right]) {
            count++; // Found a palindrome
            left--;  // Expand to the left
            right++; // Expand to the right
        }
    };

    // Iterate over all possible centers
    for (int i = 0; i < n; i++) {
        // Odd-length palindromes (single character center)
        expandAroundCenter(i, i);

        // Even-length palindromes (two consecutive character center)
        expandAroundCenter(i, i + 1);
    }

    return count;
}
};
