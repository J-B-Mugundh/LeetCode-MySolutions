class Solution {
public:
    string largestOddNumber(string s) {
        int n = s.size(), pos = -1;

        for(int i = n - 1; i >= 0; i--){
            if(s[i] == '1' || s[i] == '3' || s[i] == '5' || s[i] == '7' || s[i] == '9'){
                pos = i;
                break;
            }
        }
        return pos == -1 ? "" : s.substr(0, pos + 1);
    }
};