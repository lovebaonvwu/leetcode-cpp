class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        vector<int> cnt(101);
        for (auto n : nums) {
            ++cnt[n];
        }

        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i += 3) {
            if (all_of(begin(cnt), end(cnt), [](int c) {return c < 2;})) {
                break;
            }

            --cnt[nums[i]];
            if (i + 1 < n) {
               --cnt[nums[i + 1]]; 
            }
            if (i + 2 < n) {
                --cnt[nums[i + 2]];
            }

            ++ans;
        }

        return ans;
    }
};
// 0 ms
// 27.36 MB
