class Solution {
 public:
  int reductionOperations(vector<int>& nums) {
    vector<int> cnt(5 * 10000 + 1);

    for (auto n : nums) {
      ++cnt[n];
    }

    auto minmax = minmax_element(nums.begin(), nums.end());

    int l = *minmax.first, r = *minmax.second;

    int ans = 0, sum = 0;

    for (int i = r; i > l; --i) {
      if (cnt[i]) {
        sum += cnt[i];
        ans += sum;
      }
    }

    return ans;
  }
};
// Runtime: 308 ms, faster than 67.75%
// Memory Usage: 100.9 MB, less than 57.81%

class Solution {
 public:
  int reductionOperations(vector<int>& nums) {
    map<int, int> mp;

    for (auto n : nums) {
      ++mp[n];
    }

    int ans = 0, sum = 0;

    int i = mp.size() - 1;
    for (auto it = mp.rbegin(); i > 0; ++it, --i) {
      sum += it->second;
      ans += sum;
    }

    return ans;
  }
};
// Runtime: 684 ms, faster than 18.33%
// Memory Usage: 124.4 MB, less than 37.70%