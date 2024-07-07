class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0, sum = 0;
        while(numBottles){
            if(numBottles < numExchange){
                break;
            }
            numBottles -= numExchange;
            sum += numExchange;
            numBottles += 1;
        }
        sum += numBottles;
        return sum;
    }
};