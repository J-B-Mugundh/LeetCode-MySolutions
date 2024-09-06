class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n = s.size(), maxLen = 0;

        for(int i = 0; i < n; i++){
            vector<int> hash(26, 0);
            int maxFreq = 0;
            for(int j = i; j < n; j++){
                hash[s[j] - 'A']++;
                maxFreq = max(maxFreq, hash[s[j] - 'A']);

                int len = j - i + 1;
                int maxReplace = len - maxFreq;

                if(maxReplace <= k)
                    maxLen = max(maxLen, len);
                else
                    break;
            }
        }
        return maxLen;
    }
};