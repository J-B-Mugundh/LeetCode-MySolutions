class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> frnds;
        for(int i = 1; i <= n; i++){
            frnds.push_back(i);
        }
        int i = 0;
        while(frnds.size() > 1){
            i = (i + k - 1) % frnds.size();
            frnds.erase(frnds.begin() + i);
        }
        return frnds[0];
    }
};