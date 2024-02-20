class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() - 1;
        int cnt = 0;

        while(s[n] == ' ')
            n--;
        
        while(n >= 0 && s[n] != ' ' ){
            n--;
            cnt++;
        }
        
        return cnt;
    }
};