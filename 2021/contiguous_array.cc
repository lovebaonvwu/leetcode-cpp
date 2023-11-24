class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    int ans = 0;

    for (int i = 0, n = nums.size(); i < n; ++i) {
      for (int j = i, a = 0, b = 0; j < n; ++j) {
        nums[j] ? ++b : ++a;

        if (a == b) {
          ans = max(ans, j - i + 1);
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;

    int ans = 0;
    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      cnt += nums[i] ? -1 : 1;

      if (cnt == 0) {
        ans = max(ans, i + 1);
      } else if (mp.find(cnt) != mp.end()) {
        ans = max(ans, i - mp[cnt]);
      } else if (mp.find(cnt) == mp.end()) {
        mp[cnt] = i;
      }
    }

    return ans;
  }
};
// Runtime: 488 ms, faster than 7.84%
// Memory Usage: 83.1 MB, less than 43.89%

class Solution {
 public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> mp;

    int ans = 0;
    mp[0] = -1;

    for (int i = 0, cnt = 0; i < nums.size(); ++i) {
      cnt += nums[i] ? -1 : 1;

      if (mp.find(cnt) != mp.end()) {
        ans = max(ans, i - mp[cnt]);
      } else {
        mp[cnt] = i;
      }
    }

    return ans;
  }
};
// Runtime: 492 ms, faster than 7.32%
// Memory Usage: 82.9 MB, less than 71.42%