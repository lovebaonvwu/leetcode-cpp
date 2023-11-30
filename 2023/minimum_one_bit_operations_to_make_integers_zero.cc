class Solution {
  unordered_map<string, int> dfs_cache;
  unordered_map<string, int> helper_cache;

  int dfs(string n) {
    if (n == "0")
      return 0;
    if (n == "1")
      return 1;
    if (dfs_cache.find(n) != dfs_cache.end()) {
      return dfs_cache[n];
    }

    if (n[0] == '0')
      return dfs(n.substr(1));

    string m = n.substr(1);
    string p = m;
    p[0] = '1';
    for (int i = 1; i < p.size(); ++i) {
      p[i] = '0';
    }

    dfs_cache[n] = helper(m) + 1 + dfs(p);
    return dfs_cache[n];
  };

  int helper(string n) {
    if (n == "0")
      return 1;
    if (n == "1")
      return 0;
    if (helper_cache.find(n) != helper_cache.end()) {
      return helper_cache[n];
    }

    if (n[0] == '1') {
      helper_cache[n] = dfs(n.substr(1));
    } else {
      string m = n.substr(1);
      string p = m;
      p[0] = '1';
      for (int i = 1; i < p.size(); ++i) {
        p[i] = '0';
      }
      helper_cache[n] = helper(m) + 1 + dfs(p);
    }

    return helper_cache[n];
  };

 public:
  int minimumOneBitOperations(int n) {
    string str = bitset<32>(n).to_string();
    return dfs(str);
  }
};
// 25ms
// 23.78MB