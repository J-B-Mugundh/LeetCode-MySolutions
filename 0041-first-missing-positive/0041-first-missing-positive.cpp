class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n + 1, false);
        for (int n : nums){
            if(n > 0 && n <= n)
                seen[n] = true;
        }
        for(int i = 1; i <= n; i++){
            if(!seen[i])
                return i;
        }
        return n + 1;
    }
};