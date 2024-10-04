class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;

        for (auto n : nums) {
            int m = 0;
            while (n > 0) {
                m += n % 10;
                n /= 10;
            }

            ans = min(ans, m);
        }

        return ans;
    }
};
// 14 ms
// 27.23 MB

