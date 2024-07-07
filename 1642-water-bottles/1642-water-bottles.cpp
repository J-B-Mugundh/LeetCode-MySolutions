class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0, sum = 0;
        while(numBottles){
            if(cnt == numExchange){
                numBottles += 1;
                cnt = 0;
            } 
            numBottles -= 1;
            cnt++;
            sum++;
        }
        if(cnt == numExchange) sum++;
        return sum;
    }
};