class Solution {
 public:
  long long numberOfWays(string s) {
    unordered_map<string, long> mp(
        {{"0", 0}, {"1", 0}, {"01", 0}, {"10", 0}, {"101", 0}, {"010", 0}});

    for (auto c : s) {
      if (c == '0') {
        ++mp["0"];
        mp["10"] += mp["1"];
        mp["010"] += mp["01"];
      } else {
        ++mp["1"];
        mp["01"] += mp["0"];
        mp["101"] += mp["10"];
      }
    }

    return mp["101"] + mp["010"];
  }
};
// Time Limit Exceeded
// 2022.4.9 at 茗筑美嘉

class Solution {
 public:
  long long numberOfWays(string s) {
    long long cnt0 = 0, cnt1 = 0;
    for (auto c : s) {
      if (c == '0') {
        ++cnt0;
      } else {
        ++cnt1;
      }
    }

    long long cur0 = 0, cur1 = 0;
    long long ans = 0;
    for (auto c : s) {
      if (c == '0') {
        ans += (cur1 * cnt1);
        ++cur0;
        --cnt0;
      } else {
        ans += (cur0 * cnt0);
        ++cur1;
        --cnt1;
      }
    }

    return ans;
  }
};
// Runtime: 100 ms, faster than 96.18%
// Memory Usage: 24.3 MB, less than 92.84%
// 2022.4.9 at 茗筑美嘉