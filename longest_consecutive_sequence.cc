class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.empty()) {
      return 0;
    }

    set<int> st;

    for (auto n : nums) {
      st.insert(n);
    }

    int ans = 0, cnt = 0, prev = INT_MIN;

    for (auto it = st.begin(); it != st.end(); ++it) {
      if (*it - 1 == prev) {
        ++cnt;
        ans = max(ans, cnt);
      } else {
        cnt = 1;
      }

      prev = *it;
    }

    return max(ans, cnt);
  }
};
// Runtime: 148 ms, faster than 32.86%
// Memory Usage: 31.8 MB, less than 6.61%

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> st(nums.begin(), nums.end());

    int ans = 0;

    for (auto n : nums) {
      if (!st.count(n - 1)) {
        int cnt = 1;

        while (st.count(++n)) {
          ++cnt;
        }

        ans = max(ans, cnt);
      }
    }

    return ans;
  }
};
// Runtime: 1112 ms, faster than 8.14%
// Memory Usage: 28.8 MB, less than 26.69%

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp;

    for (auto n : nums) {
      if (mp.find(n) != mp.end()) {
        continue;
      }

      auto l = mp.find(n - 1) != mp.end() ? mp[n - 1] : 0;
      auto r = mp.find(n + 1) != mp.end() ? mp[n + 1] : 0;

      if (l > 0 && r > 0) {
        mp[n] = mp[n - l] = mp[n + r] = l + r + 1;
      } else if (l > 0) {
        mp[n] = mp[n - l] = l + 1;
      } else if (r > 0) {
        mp[n] = mp[n + r] = r + 1;
      } else {
        mp[n] = 1;
      }
    }

    int ans = 0;
    for (auto [k, v] : mp) {
      ans = max(ans, v);
    }

    return ans;
  }
};
// Runtime: 104 ms, faster than 35.95%
// Memory Usage: 30.9 MB, less than 14.35%