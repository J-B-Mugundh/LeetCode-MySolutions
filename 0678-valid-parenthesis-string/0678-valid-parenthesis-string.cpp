class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0, n = s.length(), i = 0;

        for(char c : s){
            if(c == '(')
                leftMin++, leftMax++;
            else if(c == ')')
                leftMin--, leftMax--;
            else if(c == '*')
                leftMin--, leftMax++;
            
            if(leftMax < 0) 
                return false;
            if(leftMin < 0) 
                leftMin = 0;
        }
        return leftMin == 0;
    }
};