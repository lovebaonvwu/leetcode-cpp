class Solution {
 public:
  int findLUSlength(vector<string>& strs) {
    int ans = -1;

    int n = strs.size();

    for (int i = 0; i < n; ++i) {
      bool flag = false;

      for (int j = 0; j < n; ++j) {
        if (i == j) {
          continue;
        }

        if (isSub(strs[i], strs[j])) {
          flag = true;
          break;
        }
      }

      if (!flag) {
        ans = max(ans, (int)strs[i].size());
      }
    }

    return ans;
  }

  bool isSub(string& a, string& b) {
    if (b.size() < a.size()) {
      return false;
    }

    int i = 0;
    for (int j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) {
        ++i;
      }
    }

    return i == a.size();
  }
};
// Runtime: 3 ms, faster than 70.37%
// Memory Usage: 8.3 MB, less than 63.64%
// 2021.8.27 at 奥盛大厦