class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cnt(k + 1);
        vector<int> arr_x;

        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i];
            int b = nums[n - 1 - i];
            ++cnt[abs(a - b)];
            int max_x = max(max(a, b), k - min(a, b));
            arr_x.push_back(max_x);
        }

        sort(begin(arr_x), end(arr_x));

        int ans = n;
        for (int i = 0; i <= k; ++i) {
            int need_two = lower_bound(begin(arr_x), end(arr_x), i) - begin(arr_x);

            ans = min(ans, (n / 2 - cnt[i] + need_two));
        }

        return ans;
    }
};
// 101 ms
// 113.42 MB
