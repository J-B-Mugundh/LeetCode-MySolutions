class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        for(int n : nums){
            st.insert(n);
        }
        int maxi = -1;
        for(int n : nums){
            if(n > maxi){
                if(st.find(-n) != st.end())
                    maxi = n;
            }
        }
        return maxi;
    }
};