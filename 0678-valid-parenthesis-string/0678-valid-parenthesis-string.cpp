class Solution {
public: 
    bool checkValidString(string s) {
        stack<int> openBrackets;
        stack<int> asterisks;

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (ch == '(') {
                openBrackets.push(i);
            } else if (ch == '*') {
                asterisks.push(i);
            } else {
                if (!openBrackets.empty()) {
                    openBrackets.pop();
                } else if (!asterisks.empty()) {
                    asterisks.pop();
                } else {
                    return false;
                }
            }
        }

        while (!openBrackets.empty() && !asterisks.empty()) {
            if (openBrackets.top() > asterisks.top()) {
                return false;
            }
            openBrackets.pop();
            asterisks.pop();
        }

        return openBrackets.empty();
    }
};