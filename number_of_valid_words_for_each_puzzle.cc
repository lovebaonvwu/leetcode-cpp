class Solution {
 public:
  vector<int> findNumOfValidWords(vector<string>& words,
                                  vector<string>& puzzles) {
    vector<vector<int>> pattern;

    for (auto& w : words) {
      vector<int> p(26);

      for (auto c : w) {
        ++p[c - 'a'];
      }

      pattern.push_back(p);
    }

    int n = puzzles.size();

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      vector<int> cur(26);

      for (auto c : puzzles[i]) {
        ++cur[c - 'a'];
      }

      int cnt = 0;

      for (int j = 0; j < pattern.size(); ++j) {
        bool valid = true;

        char firstLetter = puzzles[i][0];

        if (pattern[j][firstLetter - 'a'] == 0) {
          valid = false;
        }

        for (int k = 0; valid && k < pattern[j].size(); ++k) {
          if (pattern[j][k] && cur[k] == 0) {
            valid = false;
            break;
          }
        }

        if (valid) {
          ++cnt;
        }
      }

      ans[i] = cnt;
    }

    return ans;
  }
};
// Time Limit Exceeded
// 2021.11.9 at 奥盛大厦

class Solution {
 public:
  vector<int> findNumOfValidWords(vector<string>& words,
                                  vector<string>& puzzles) {
    unordered_map<int, int> mp;

    for (auto& w : words) {
      int mask = 0;

      for (auto c : w) {
        mask |= 1 << (c - 'a');
      }

      ++mp[mask];
    }

    vector<int> ans;

    for (auto& p : puzzles) {
      int mask = 0;
      for (auto c : p) {
        mask |= 1 << (c - 'a');
      }

      int first = p[0] - 'a';
      int cur = mask;
      int cnt = 0;

      while (cur) {
        if (cur & (1 << first)) {
          auto it = mp.find(cur);

          if (it != mp.end()) {
            cnt += mp[cur];
          }
        }

        cur = (cur - 1) & mask;
      }

      ans.push_back(cnt);
    }

    return ans;
  }
};
// Runtime: 108 ms, faster than 97.62%
// Memory Usage: 35 MB, less than 89.52%
// 2021.11.9 at 奥盛大厦