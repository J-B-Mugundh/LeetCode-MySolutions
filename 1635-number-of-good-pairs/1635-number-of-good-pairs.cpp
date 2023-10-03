class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int n : nums)
            mp[n]++;
        
        int sum = 0;

        for(auto num : mp){
            int n = num.second;
            sum += n * (n - 1) / 2;
        }

        return sum;
    }
};