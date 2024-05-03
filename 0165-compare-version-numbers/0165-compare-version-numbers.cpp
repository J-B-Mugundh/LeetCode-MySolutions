class Solution {
public:
    int compareVersion(string v1, string v2) {
        int p1 = 0, p2 = 0;

        while (p1 < v1.size() || p2 < v2.size()) {
            int num1 = 0, num2 = 0;

            // Parse the next revision in v1
            while (p1 < v1.size() && v1[p1] != '.') {
                num1 = num1 * 10 + (v1[p1] - '0');
                p1++;
            }

            // Parse the next revision in v2
            while (p2 < v2.size() && v2[p2] != '.') {
                num2 = num2 * 10 + (v2[p2] - '0');
                p2++;
            }

            // Compare the two revisions
            if (num1 > num2)
                return 1;
            else if (num1 < num2)
                return -1;

            // Move to the next character after '.'
            p1++;
            p2++;
        }

        return 0;
    }
};
