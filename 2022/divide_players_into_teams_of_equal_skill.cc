class Solution {
 public:
  long long dividePlayers(vector<int>& skill) {
    int sum = accumulate(begin(skill), end(skill), 0);
    int n = skill.size();
    if (sum % (n / 2) != 0) {
      return -1;
    }

    unordered_map<long long, long long> mp;
    for (auto n : skill) {
      ++mp[n];
    }

    int target = sum / (n / 2);

    long long ans = 0;
    for (auto [n, cnt] : mp) {
      if (cnt > 0 && mp.find(target - n) != mp.end()) {
        if (n == (target - n)) {
          ans += (cnt / 2) * n * (target - n);
          mp[n] -= (cnt / 2) * 2;
        } else {
          ans += cnt * n * (target - n);
          cnt = min(cnt, mp[target - n]);
          mp[n] -= cnt;
          mp[target - n] -= cnt;
        }
      }
    }

    for (auto [n, cnt] : mp) {
      if (cnt > 0) {
        return -1;
      }
    }

    return ans;
  }
};
// Runtime 77 ms
// Memory 53 MB
// 2022.12.29 at 奥盛大厦