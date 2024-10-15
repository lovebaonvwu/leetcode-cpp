class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (auto p : nums) {
            if (p % 2 == 0) {
                ans.push_back(-1);
            } else {
                for (int i = 1; i < 31; ++i) {
                    if ((p & (1 << i)) == 0) {
                        p = p ^ (1 << (i - 1));
                        break;
                    }
                }
                ans.push_back(p);
            }
        }

        return ans;
    }
};
// 0 ms
// 27.49 MB

