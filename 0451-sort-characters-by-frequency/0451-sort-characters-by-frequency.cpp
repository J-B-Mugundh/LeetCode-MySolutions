class Solution {
public:
    string frequencySort(string s) {
    //  Create a hash map to store the frequency of each character
    unordered_map<char, int> char_freq;
    for (char c : s) {
        char_freq[c]++;
    }
    
    // Sort the characters based on their frequencies in decreasing order using lambda function
    sort(s.begin(), s.end(), [&](char a, char b) {
        if (char_freq[a] != char_freq[b]) {
            return char_freq[a] > char_freq[b];
        } else {
            return a < b;
        }
    });
    
    return s;
    }
};