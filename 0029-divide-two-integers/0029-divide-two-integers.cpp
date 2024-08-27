class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle special cases
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (dividend == INT_MIN && divisor == 1)
            return INT_MIN;

        // Determine the sign of the result
        bool negative = (dividend < 0) ^ (divisor < 0);

        // Convert both dividend and divisor to positive
        long long absDividend = abs((long long)dividend);
        long long absDivisor = abs((long long)divisor);

        // Initialize the quotient to 0
        long long quotient = 0;

        // Repeatedly subtract divisor from dividend until dividend becomes less than divisor
        while (absDividend >= absDivisor) {
            long long tempDivisor = absDivisor;
            long long multiple = 1;

            // Find the maximum multiple of divisor that can be subtracted from dividend
            while (absDividend >= (tempDivisor << 1)) {
                tempDivisor <<= 1;
                multiple <<= 1;
            }

            // Subtract the multiple of divisor from dividend
            absDividend -= tempDivisor;
            quotient += multiple;
        }

        // Handle the sign of the quotient
        if (negative)
            quotient = -quotient;

        // Check for overflow and return the result
        return (quotient >= INT_MAX) ? INT_MAX : quotient;
    }
};
