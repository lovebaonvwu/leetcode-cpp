class Solution {
 public:
  int minCost(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> cached(n, -1);

    function<long long(int)> dfs = [&](int cur) -> long long {
      if (cur == n)
        return 0;

      if (cached[cur] != -1) {
        return cached[cur];
      }

      long long ret = LONG_MAX;
      vector<int> cnt(n);
      for (int i = cur; i < n; ++i) {
        ++cnt[nums[i]];
        int val = 0;
        for (int j = 0; j < n; ++j) {
          if (cnt[j] > 1) {
            val += cnt[j];
          }
        }
        ret = min(ret, k + val + dfs(i + 1));
      }

      return cached[cur] = ret;
    };

    return dfs(0);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int minCost(vector<int>& nums, int k) {
    int n = nums.size();

    vector<int> cached(n, -1);

    function<long long(int)> dfs = [&](int cur) -> long long {
      if (cur == n)
        return 0;

      if (cached[cur] != -1) {
        return cached[cur];
      }

      long long ret = LONG_MAX;
      vector<int> cnt(n);
      int val = 0;
      for (int i = cur; i < n; ++i) {
        ++cnt[nums[i]];
        if (cnt[nums[i]] == 2)
          val += 2;
        else if (cnt[nums[i]] > 2) {
          ++val;
        }
        ret = min(ret, k + val + dfs(i + 1));
      }

      return cached[cur] = ret;
    };

    return dfs(0);
  }
};
// 331 ms
// 135.07 MB