class Solution {
public:
    bool canBeValid(string s, string locked) {
        if(s.size() % 2) return false;
        
        for(int i = 0; i < s.size(); i++){
            if(locked[i] == '0')
                s[i] = '*';
        }

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

        if(openBrackets.size() % 2) return false;

        return openBrackets.empty();
    }
};