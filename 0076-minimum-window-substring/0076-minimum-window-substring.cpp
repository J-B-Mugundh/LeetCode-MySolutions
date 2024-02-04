class Solution {
public:
    string minWindow(string s, string t) {
        if (!t.size()) return "";

        unordered_map<char, int> T, W;
        for (char c : t) T[c]++;

        int have = 0, need = T.size();
        int l = 0, rStart = -1, rLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            char c = s[r];
            W[c]++;

            if (T.count(c) && W[c] == T[c]) have++;

            while (have == need) { 
                if (r - l + 1 < rLen) {
                    rLen = r - l + 1;
                    rStart = l;
                }

                W[s[l]]--; 
                if (T.count(s[l]) && W[s[l]] < T[s[l]]) have--;
                l++;
            }
        }

        return rLen == INT_MAX ? "" : s.substr(rStart, rLen);
    }
};
