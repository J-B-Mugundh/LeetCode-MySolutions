class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<int, int> mp;
        for(char c : s)
            mp[c]++;
        bool flag = false;
        int len = 0, maxOdd = 0;
        for(auto it : mp){
            if(it.second % 2 == 0)
                len += it.second;
            else{
                maxOdd = max(maxOdd, it.second);
            }
        }
        return len + maxOdd;
    }
};