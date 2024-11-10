class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int sum = 1;
            int tmp = n;
            while (tmp > 0) {
                sum *= tmp % 10;
                tmp /= 10;
            }

            if (sum % t == 0) {
                return n;
            }

            ++n;
        }
        return -1;
    }
};
// 0 ms
// 8.46 MB

