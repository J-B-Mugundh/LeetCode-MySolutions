class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor2no = 0;
        for (int num : nums) {
            xor2no ^= num;
        }

        // Cast xor2no to unsigned to avoid undefined behavior with -INT_MIN
        unsigned int lowestBit = xor2no & -(unsigned int)xor2no;

        vector<int> result(2, 0);
        for (int num : nums) {
            if ((lowestBit & num) == 0) {
                result[0] ^= num;
            } else {
                result[1] ^= num;
            }
        }

        return result;
    }
};