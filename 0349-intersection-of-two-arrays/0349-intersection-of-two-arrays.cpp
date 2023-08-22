class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1(nums1.begin(), nums1.end());
        set<int> s2;

        for(int i : nums2){
            if(s1.find(i) != s1.end())
                s2.insert(i);
        }

        return vector<int>(s2.begin(), s2.end());
    }
};