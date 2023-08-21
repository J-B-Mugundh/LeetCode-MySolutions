class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            // Odd length palindrome
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            // Even length palindrome
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};