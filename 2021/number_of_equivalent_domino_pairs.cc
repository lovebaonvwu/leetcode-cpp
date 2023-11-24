class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;

    unordered_map<string, int> mp;

    for (auto& d : dominoes) {
      string k;

      if (d[0] > d[1]) {
        k += (d[1] + '0');
        k += (d[0] + '0');
      } else {
        k += (d[0] + '0');
        k += (d[1] + '0');
      }

      if (mp.find(k) != mp.end()) {
        ans += mp[k];
      }

      ++mp[k];
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 65.01%
// Memory Usage: 21.1 MB, less than 100.00%

class Solution {
 public:
  int numEquivDominoPairs(vector<vector<int>>& dominoes) {
    int ans = 0;

    unordered_map<int, int> mp;

    for (auto& d : dominoes) {
      ans += mp[min(d[0], d[1]) * 10 + max(d[0], d[1])]++;
    }

    return ans;
  }
};
// Runtime: 52 ms, faster than 52.83%
// Memory Usage: 21.3 MB, less than 100.00%