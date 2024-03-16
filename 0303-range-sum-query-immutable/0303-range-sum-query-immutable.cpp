class NumArray {
public:
    vector<int> mp;
    NumArray(vector<int>& nums) {
        int sum = 0;
        mp.push_back(sum);
        for(int num : nums){
            sum += num;
            mp.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        return mp[right + 1] - mp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */