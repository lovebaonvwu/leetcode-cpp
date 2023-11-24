class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> mp;

    for (auto n : answers) {
      ++mp[n];
    }

    int ans = 0;
    for (auto& [rab, cnt] : mp) {
      while (cnt > 0) {
        ans += rab + 1;
        cnt -= rab + 1;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 42.42%
// Memory Usage: 8.8 MB, less than 50.00%

class Solution {
 public:
  int numRabbits(vector<int>& answers) {
    unordered_map<int, int> mp;

    for (auto n : answers) {
      ++mp[n];
    }

    int ans = 0;
    for (auto& [rab, cnt] : mp) {
      ans += static_cast<int>(ceil(cnt / (rab + 1.0))) * (rab + 1);
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 42.42%
// Memory Usage: 8.6 MB, less than 100.00%