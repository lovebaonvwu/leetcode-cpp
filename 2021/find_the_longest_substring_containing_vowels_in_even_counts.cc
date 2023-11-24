class Solution {
 public:
  int findTheLongestSubstring(string s) {
    int ans = 0;

    for (int i = 0; i < s.size(); ++i) {
      vector<int> cnt(26);
      for (int j = i; j < s.size(); ++j) {
        if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
            s[j] == 'u') {
          ++cnt[s[j] - 'a'];
        }

        if (all_of(cnt.begin(), cnt.end(), [](int n) { return n % 2 == 0; })) {
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
  int findTheLongestSubstring(string s) {
    constexpr char mask[26] = {1, 0, 0, 0, 2, 0, 0, 0,  4, 0, 0, 0, 0,
                               0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};

    vector<int> bits(32, -1);

    int ans = 0;
    for (int i = 0, cur = 0; i < s.size(); ++i) {
      cur ^= mask[s[i] - 'a'];

      if (cur > 0 && bits[cur] == -1) {
        bits[cur] = i;
      }

      ans = max(ans, i - bits[cur]);
    }

    return ans;
  }
};
// Runtime: 136 ms, faster than 68.75%
// Memory Usage: 16.2 MB, less than 100.00%

class Solution {
 public:
  int findTheLongestSubstring(string s) {
    unordered_map<int, int> mp = {{0, -1}};

    int ans = 0;
    string ss = "aeiou";
    for (int i = 0, cur = 0; i < s.size(); ++i) {
      cur ^= 1 << (ss.find(s[i]) + 1) >> 1;

      if (!mp.count(cur)) {
        mp[cur] = i;
      }

      ans = max(ans, i - mp[cur]);
    }

    return ans;
  }
};
// Runtime: 356 ms, faster than 28.27%
// Memory Usage: 16.5 MB, less than 100.00%