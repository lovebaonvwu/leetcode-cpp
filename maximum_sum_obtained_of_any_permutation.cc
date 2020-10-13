class Solution {
 public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    unordered_map<int, int> cnt;

    for (auto& r : requests) {
      for (int i = r[0]; i <= r[1]; ++i) {
        ++cnt[i];
      }
    }

    vector<pair<int, int>> vp;

    for (auto c : cnt) {
      vp.push_back({c.second, c.first});
    }

    sort(vp.begin(), vp.end(),
         [](auto& a, auto& b) { return a.first > b.first; });

    sort(nums.begin(), nums.end(), greater<int>());

    long ans = 0;

    for (int i = 0; i < vp.size(); ++i) {
      ans += vp[i].first * nums[i];
    }

    return ans % 1000000007;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    vector<int> cnt(nums.size());

    for (auto& r : requests) {
      for (int i = r[0]; i <= r[1]; ++i) {
        ++cnt[i];
      }
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    sort(nums.begin(), nums.end(), greater<int>());

    long ans = 0;

    for (int i = 0; i < cnt.size(); ++i) {
      ans += cnt[i] * nums[i];
    }

    return ans % 1000000007;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
    int n = nums.size();

    vector<long> cnt(n);

    for (auto& r : requests) {
      ++cnt[r[0]];

      if (r[1] + 1 < n) {
        --cnt[r[1] + 1];
      }
    }

    for (int i = 1; i < n; ++i) {
      cnt[i] += cnt[i - 1];
    }

    sort(cnt.begin(), cnt.end(), greater<int>());

    sort(nums.begin(), nums.end(), greater<int>());

    long ans = 0;

    for (int i = 0; i < cnt.size(); ++i) {
      ans += cnt[i] * nums[i];
    }

    return ans % 1000000007;
  }
};
// Runtime: 940 ms, faster than 50.26%
// Memory Usage: 122 MB, less than 5.58%