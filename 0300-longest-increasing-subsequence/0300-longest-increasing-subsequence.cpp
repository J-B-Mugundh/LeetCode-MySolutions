class Solution {
public:
    // // Memoization
    // int f(int ind, int prev_ind, vector<int>& nums, int n, vector<vector<int>> &dp){
    //     if(ind == n) return 0;

    //     if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

    //     // Not take
    //     int len = f(ind + 1, prev_ind, nums, n, dp);

    //     // Take
    //     if(prev_ind == -1 || nums[ind] > nums[prev_ind])
    //         len = max(len, 1 + f(ind + 1, ind, nums, n, dp));
        
    //     return dp[ind][prev_ind + 1] = len;
    // }

    // // Since we have -1 in prev_ind, so doing coordinate change. ie -1 => 0, 0 => 1, ...
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n, vector<int>(n+1, -1));
    //     return f(0, -1, nums, n, dp);
    // }

    // // Tabulation
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n + 1, vector<int>(n+1, 0));
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
    //             // Not take
    //             // Whenever converting into dp, coordinate shift has to be done! So, 2nd param will be in + 1 state
    //             int len = dp[ind + 1][prev_ind + 1];
    //             if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
    //                 len = max(len, 1 + dp[ind + 1][ind + 1]);
    //             }
    //             dp[ind][prev_ind + 1] = len;
    //         }
    //     }
    //     return dp[0][-1+1];
    // }

    // // Space Optimized
    // int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> next(n+1, 0), cur(n+1, 0);
    //     for(int ind = n - 1; ind >= 0; ind--){
    //         for(int prev_ind = ind - 1; prev_ind >= -1; prev_ind--){
    //             // Not take
    //             // Whenever converting into dp, coordinate shift has to be done! So, 2nd param will be in + 1 state
    //             int len = next[prev_ind + 1];
    //             if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
    //                 len = max(len, 1 + next[ind + 1]);
    //             }
    //             cur[prev_ind + 1] = len;
    //         }
    //         next = cur;
    //     }
    //     return cur[-1+1];
    // }

    // //Better approach: T.C => O(n^2), S.c => O(n)
    //     int lengthOfLIS(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<int> dp(n, 1);
    //     int maxi = 1;
    //     for(int i = 0; i < n; i++){
    //         for(int prev = 0; prev < i; prev++){
    //             if(nums[prev] < nums[i])
    //                 dp[i] = max(dp[i], 1 + dp[prev]);
    //         }
    //         maxi = max(maxi, dp[i]);
    //     }
    //     return maxi;
    // }

    // // BONUS: Do a small change in above code for => Maximum sum increasing subsequence (another qn)
    // int maxSumIS(int nums[], int n)  
	// {  
    //     vector<int> dp(n, 0);
    //     for(int i = 0; i < n; i++) dp[i] = nums[i];
    //     int maxi = 1;
    //     for(int i = 0; i < n; i++){
    //         for(int prev = 0; prev < i; prev++){
    //             if(nums[prev] < nums[i])
    //                 dp[i] = max(dp[i], nums[i] + dp[prev]);
    //         }
    //         maxi = max(maxi, dp[i]);
    //     }
    //     return maxi;
	// } 

    // Optimized Approach: Using Binary Search (Lower bound) => T.C = O(n log n), S.C = O(Length of LIS)

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len = 1;
        for(int i = 1; i < n; i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }

};