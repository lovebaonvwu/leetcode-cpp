class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (auto t : tasks) {
      ++cnt[t];
    }

    int ans = 0;
    for (auto c : cnt) {
      if (c.second == 1) {
        return -1;
      }

      ans += (c.second + 3 - 1) / 3;
    }

    return ans;
  }
};
// Runtime: 217 ms, faster than 90.43%
// Memory Usage: 103.6 MB, less than 69.79%
// 2022.4.19 at 奥盛大厦

class Solution {
 public:
  int minimumRounds(vector<int>& tasks) {
    unordered_map<int, int> cnt;
    for (auto t : tasks) {
      ++cnt[t];
    }

    int ans = 0;
    for (auto c : cnt) {
      if (c.second == 1) {
        return -1;
      }

      while (c.second % 3 != 0) {
        ans += 1;
        c.second -= 2;
      }

      ans += c.second / 3;
    }

    return ans;
  }
};
// Runtime: 242 ms, faster than 60.31%
// Memory Usage: 103.6 MB, less than 69.79%
// 2022.4.19 at 奥盛大厦