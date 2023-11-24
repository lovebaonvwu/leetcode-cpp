class Solution {
 public:
  int punishmentNumber(int n) {
    int ans = 0;

    for (int i = 1; i <= n; ++i) {
      int p = i * i;

      ans += dfs(to_string(p), i) ? p : 0;
    }

    return ans;
  }

  bool dfs(string s, int target) {
    if (s == "" && target == 0) {
      return true;
    }

    if (target < 0) {
      return false;
    }

    for (int i = 0; i < s.size(); ++i) {
      string t = s.substr(0, i + 1);
      int val = stoi(t);

      string next = s.substr(i + 1);

      if (dfs(next, target - val)) {
        return true;
      }
    }

    return false;
  }
};
// Runtime 458 ms
// Memory 5.9 MB