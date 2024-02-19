class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        vector<int> ans;
        while(left <= right){
            int l = nums[left] * nums[left], r = nums[right] * nums[right];
            if(l >= r)
            {
                ans.push_back(l); 
                left++;
            }       
            else
            {
                ans.push_back(r); 
                right--;
            }
                
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};