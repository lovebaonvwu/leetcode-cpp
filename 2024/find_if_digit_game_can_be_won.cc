class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int sum1 = 0;
        int sum2 = 0;

        for (auto n : nums) {
            if (n >= 1 && n < 10) {
                sum1 += n;
            } else {
                sum2 += n;
            }
        }

        return sum1 != sum2;
    }
};
// 9 ms
// 28.06 MB
