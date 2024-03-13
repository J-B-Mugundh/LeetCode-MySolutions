class Solution {
public:
    int pivotInteger(int n) {
        int l = 1, r = n;
        int ls = 0, rs = 0, total = n * (n + 1) / 2;

        while(l <= r){
            int mid = (l + r) / 2;
            ls = (mid * (mid + 1) / 2);
            rs = total - ls + mid;
            cout << "mid = " << mid << ", ls = " << ls << ", rs = " << rs << endl;

            if(ls == rs)
                return mid;
            else if(ls < rs)
                l = mid + 1;
            else 
                r = mid - 1;
        }
        return -1;
    }
};