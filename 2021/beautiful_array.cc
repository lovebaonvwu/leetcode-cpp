class Solution {
 public:
  vector<int> beautifulArray(int n) {
    vector<int> ans = {1};

    while (ans.size() < n) {
      vector<int> tmp;

      for (auto x : ans) {
        if (2 * x - 1 <= n) {
          tmp.push_back(2 * x - 1);
        }
      }

      for (auto x : ans) {
        if (2 * x <= n) {
          tmp.push_back(2 * x);
        }
      }

      ans = tmp;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 73.17%
// Memory Usage: 7.2 MB, less than 73.52%
// 2021.7.28 at 奥盛大厦