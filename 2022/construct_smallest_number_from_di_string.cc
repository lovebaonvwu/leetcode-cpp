class Solution {
 public:
  string smallestNumber(string pattern) {
    string ans;
    unordered_set<char> visited;
    for (int i = '1'; i <= '9'; ++i) {
      visited.insert(i);
      ans.push_back(i);
      if (dfs(pattern, ans, visited, 0)) {
        return ans;
      }
      ans.pop_back();
      visited.erase(i);
    }

    return ans;
  }

  bool dfs(string p, string& s, unordered_set<char> visited, int i) {
    if (i == p.size()) {
      return true;
    }

    for (int j = '1'; j <= '9'; ++j) {
      if (visited.find(j) != visited.end()) {
        continue;
      }

      if (p[i] == 'I' && j <= s.back()) {
        continue;
      }

      if (p[i] == 'D' && j >= s.back()) {
        continue;
      }

      visited.insert(j);
      s.push_back(j);
      if (dfs(p, s, visited, i + 1)) {
        return true;
      }
      s.pop_back();
      visited.erase(j);
    }

    return false;
  }
};
// Runtime: 3 ms, faster than 70.00%
// Memory Usage: 7.1 MB, less than 15.00%
// 2022.8.15 at 奥盛大厦