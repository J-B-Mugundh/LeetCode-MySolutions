class Solution {
public:
        unordered_map<char, string> numMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    void backtrack(string &digits, string combinations, vector<string> &res, int index)
    {
        if(index == digits.size())
        {
            res.push_back(combinations);
            return;
        }

        char digit = digits[index];

        for(char letter : numMap[digit])
            backtrack(digits, combinations + letter, res, index + 1);
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> res;
        backtrack(digits, "", res, 0);
        return res;
    }
};