class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> mp;
        char ans;
        for(char c : s){
            mp[c]++;
        }
        for(char c : t){
            if(mp.find(c) == mp.end() || mp[c] == 0)
            {
                ans = c;
                break;  
            }
            mp[c]--;
        }
        return ans;
    }
};