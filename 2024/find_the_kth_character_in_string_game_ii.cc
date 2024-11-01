class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        long long n = 1;

        int cnt = 0;
        while (n < k) {
            n *= 2;
            ++cnt;
        }

        int shift = 0;
        for (int i = cnt - 1; i >= 0; --i) {
            if (k > n / 2) {
                if (operations[i] == 1) {
                    ++shift;
                } 
                k -= n / 2;
            }
            n /= 2;
        }

        return 'a' + shift % 26;
    }
};
// 0 ms
// 27.62 MB

