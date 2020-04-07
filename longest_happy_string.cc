class Solution {
 public:
  string longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> cnt = {{a, 'a'}, {b, 'b'}, {c, 'c'}};

    string ans;

    for (int i = 0; i < a + b + c; ++i) {
      sort(cnt.begin(), cnt.end(), greater<pair<int, char>>());

      for (auto& c : cnt) {
        if (c.first == 0) {
          break;
        }
        if (ans.size() < 2 ||
            !(ans.back() == c.second && ans[ans.size() - 2] == c.second)) {
          ans.push_back(c.second);
          --c.first;
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 100.00%