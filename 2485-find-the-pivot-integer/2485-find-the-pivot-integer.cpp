class Solution {
public:
    int pivotInteger(int n) {
        if(n == 1) return 1;
        int left = 2, right = n - 1;
        int sl = left - 1, sr = right + 1;

        while(left <= right){
            if(sl <= sr){
                if(sl == sr && left == right) return left;
                sl += left;
                left += 1;
                cout << "sl = " << sl << endl;
            }
            else if(sl > sr){
                sr += right;
                right -= 1;
                cout << "sr = " << sr << endl;
            }

        }
        return -1;
    }
};