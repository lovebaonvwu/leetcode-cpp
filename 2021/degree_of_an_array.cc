class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    unordered_map<int, int> mp, first;

    int d = 0;
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
      ++mp[nums[i]];

      if (first.find(nums[i]) == first.end()) {
        first[nums[i]] = i;
      }

      if (mp[nums[i]] > d) {
        ans = i - first[nums[i]] + 1;
        d = mp[nums[i]];
      } else if (mp[nums[i]] == d) {
        ans = min(ans, i - first[nums[i]] + 1);
      }
    }

    return ans;
  }
};
// Runtime: 44 ms, faster than 70.57%
// Memory Usage: 13.2 MB, less than 100.00%

class Solution {
 public:
  int findShortestSubArray(vector<int>& nums) {
    vector<int> cnt(50000);

    int mx = 0;
    for (auto n : nums) {
      ++cnt[n];

      mx = max(mx, cnt[n]);
    }

    int ans = INT_MAX;

    for (int i = 0; i < cnt.size(); ++i) {
      if (cnt[i] == mx) {
        int lo = 0, hi = 0;
        for (int j = 0; j < nums.size(); ++j) {
          if (nums[j] == i) {
            lo = j;
            break;
          }
        }

        for (int j = nums.size() - 1; j >= 0; --j) {
          if (nums[j] == i) {
            hi = j;
            break;
          }
        }

        ans = min(ans, hi - lo + 1);
      }
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 9.38%
// Memory Usage: 32.1 MB, less than 9.09%