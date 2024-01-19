class Solution {
 public:
  long long numberOfPowerfulInt(long long start,
                                long long finish,
                                int limit,
                                string s) {
    int base = s.size();
    long long ans = 0;
    long long tail = stoll(s);

    vector<long long> nums{tail};
    while (nums.back() <= finish) {
      vector<long long> tmp = nums;
      for (int i = 0; i <= limit; ++i) {
        for (auto n : tmp) {
          nums.push_back(i * pow(10, base) + n);
        }
      }

      ++base;
    }

    unordered_set<long long> st(nums.begin(), nums.end());
    for (auto n : st) {
      if (n >= start && n <= finish) {
        ++ans;
      }
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  long long numberOfPowerfulInt(long long start,
                                long long finish,
                                int limit,
                                string s) {
    function<long long(const string&, int, bool)> dfs =
        [&](const string& target, int cur, bool same) -> long long {
      if (cur == target.size() - s.size()) {
        if (!same || target.substr(cur) >= s) {
          return 1;
        }

        return 0;
      }

      if (!same) {
        int p = target.size() - s.size() - cur;
        return pow(limit + 1, p);
      }

      long long res = 0;
      for (int i = 0; i <= min(limit, target[cur] - '0'); ++i) {
        if (i == target[cur] - '0') {
          res += dfs(target, cur + 1, true);
        } else {
          res += dfs(target, cur + 1, false);
        }
      }

      return res;
    };

    return dfs(to_string(finish), 0, true) - dfs(to_string(start - 1), 0, true);
  }
};
// 3 ms
// 6.98 MB