class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int sum = 0, maxi = 0;
        for(int n : gain){
            sum += n;
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};