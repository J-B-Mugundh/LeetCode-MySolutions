class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> T, W;

        for(int i = 0; i < t.size(); i++)
            T[t[i]] += 1;
        
        int have = 0, need = t.size();

        int l = 0;

        int rStart = -1, rLen = INT_MAX;

        for(int r = 0; r < s.size(); r++){
            char c = s[r];
            W[c] += 1;

            if(T.find(c) != T.end() && W[c] == T[c])
                have += 1;
            
            while(have == need){
                if((r - l + 1) < rLen){
                    rLen = r - l + 1;
                    rStart = l;
                }

                W[s[l]]--;

                if(T.find(s[l]) != T.end() && W[s[l]] < T[s[l]])
                    have -= 1;
                
                l++;
            }
        }
        return rLen == INT_MAX ? "" : s.substr(rStart, rLen);
    }
};