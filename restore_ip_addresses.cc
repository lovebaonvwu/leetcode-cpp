class Solution {
  vector<string> ans;

 public:
  vector<string> restoreIpAddresses(string s) {
    if (s.size() > 12) {
      return vector<string>();
    }

    dfs(s, std::move(""), 0, 4);

    return ans;
  }

  void dfs(const string& s, string ip, int cur, int cnt) {
    if (cur > s.size()) {
      return;
    }
    if (cur == s.size() && cnt == 0) {
      ans.push_back(ip);
      return;
    } else if (cur == s.size() || (cur < s.size() && cnt == 0)) {
      return;
    }

    for (int i = 1; i <= 3; ++i) {
      string t = s.substr(cur, i);
      if (t.size() > 1 && t[0] == '0') {
        return;
      }

      int val = std::stoi(t);
      if (val > 255) {
        return;
      }

      dfs(s, ip + t + (cnt > 1 ? "." : ""), cur + i, cnt - 1);
    }
  }
};
// Runtime 0 ms
// Memory 6.7 MB
// 2023.1.21 at 茗筑美嘉