class Solution {
 public:
  int minTimeToType(string word) {
    int ans = word.size();

    int prev = 0;

    for (auto c : word) {
      int i = c - 'a';

      if (i >= prev) {
        ans += min(i - prev, 26 - (i - prev));
      } else {
        ans += min(prev - i, 26 - (prev - i));
      }

      prev = i;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 99.25%
// 2021.11.6 at 茗筑美嘉

class Solution {
 public:
  int minTimeToType(string word) {
    int ans = word.size();

    int prev = 0;

    for (auto c : word) {
      int i = c - 'a';

      if (i < prev) {
        i += 26;
      }

      ans += min(i - prev, 26 - (i - prev));

      prev = c - 'a';
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 88.71%
// 2021.11.6 at 茗筑美嘉