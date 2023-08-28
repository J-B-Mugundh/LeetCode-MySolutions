class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int i, sum = 0;
        for(i = 0; i < n; i++){
            sum += i;
            sum -= nums[i];
        }
        sum += i;
        return sum; 
    }
};