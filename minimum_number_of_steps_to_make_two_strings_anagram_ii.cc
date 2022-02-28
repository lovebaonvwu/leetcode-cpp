class Solution {
 public:
  int minSteps(string s, string t) {
    int cnt_s[26] = {0};

    for (auto c : s) {
      ++cnt_s[c - 'a'];
    }

    int cnt_t[26] = {0};

    for (auto c : t) {
      ++cnt_t[c - 'a'];
    }

    int ans = 0;

    for (int i = 0; i < (sizeof(cnt_s) / sizeof(cnt_s[0])); ++i) {
      ans += (abs(cnt_s[i] - cnt_t[i]));
    }

    return ans;
  }
};
// Runtime: 116 ms, faster than 77.78%
// Memory Usage: 28.9 MB, less than 33.33%
// 2022.2.28 at 奥盛大厦, 3 - 719