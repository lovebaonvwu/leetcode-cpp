class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int cnt[60]{0};

    int ans = 0;
    for (auto n : time) {
      ans += cnt[(60 - n % 60) % 60];
      ++cnt[n % 60];
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 93.91%
// Memory Usage: 11.8 MB, less than 46.15%

class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    int ans = 0, n = time.size();

    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if ((time[i] + time[j]) % 60 == 0) {
          ++ans;
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded