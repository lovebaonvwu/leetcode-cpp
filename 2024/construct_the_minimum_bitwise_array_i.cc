class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for (auto n : nums) {
            if (n % 2 == 0) {
                ans.push_back(-1);
            } else {
                for (int i = 1; i < 31; ++i) {
                    if ((n & (1 << i)) == 0) {
                        n ^= (1 << (i - 1));
                        break;
                    }
                }

                ans.push_back(n);
            }
        }

        return ans;
    }
};
// 1 ms
// 24.41 MB