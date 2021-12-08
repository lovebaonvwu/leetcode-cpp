class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    if (k == 0) {
      return nums;
    }

    int n = nums.size();

    vector<int> ans(n, -1);

    long sum = accumulate(nums.begin(), nums.begin() + min(2 * k + 1, n), 0L);
    int cnt = 2 * k + 1;

    for (int i = 0, j = 2 * k; j < n;) {
      ans[i + (j - i) / 2] = sum / cnt;
      sum -= nums[i++];
      sum += ++j < n ? nums[j] : 0;
    }

    return ans;
  }
};
// Runtime: 329 ms, faster than 14.18%
// Memory Usage: 130 MB, less than 61.13%
// 2021.12.8 at 奥盛大厦

class Solution {
 public:
  vector<int> getAverages(vector<int>& nums, int k) {
    if (k == 0) {
      return nums;
    }

    int n = nums.size();

    vector<long> sum(n + 1);
    for (int i = 1; i < sum.size(); ++i) {
      sum[i] = sum[i - 1] + nums[i - 1];
    }

    vector<int> ans(n, -1);
    for (int i = 0, j = 2 * k, cnt = 2 * k + 1; j < n; ++j, ++i) {
      ans[i + (j - i) / 2] = (sum[j + 1] - sum[i]) / cnt;
    }

    return ans;
  }
};
// Runtime: 281 ms, faster than 26.47%
// Memory Usage: 138.2 MB, less than 37.28%
// 2021.12.7 at 奥盛大厦