class Solution {
  unordered_map<int, vector<int>> tree;
  int ans = 0;

 public:
  int longestPath(vector<int>& parent, string s) {
    for (int i = 0; i < parent.size(); ++i) {
      tree[parent[i]].push_back(i);
    }

    return max(ans, dfs(0, s));
  }

  int dfs(int root, const string& s) {
    int firstMaxCnt = 0;
    int secondMaxCnt = 0;

    if (tree[root].empty()) {
      return 1;
    }

    for (auto next : tree[root]) {
      int nextCnt = dfs(next, s);

      if (s[root] == s[next]) {
        ans = max(ans, nextCnt);
        nextCnt = 0;
      }

      if (nextCnt > firstMaxCnt) {
        secondMaxCnt = firstMaxCnt;
        firstMaxCnt = nextCnt;
      } else if (nextCnt > secondMaxCnt) {
        secondMaxCnt = nextCnt;
      }
    }

    ans = max(ans, firstMaxCnt + secondMaxCnt + 1);

    return firstMaxCnt + 1;
  }
};
// Runtime 716 ms
// Memory 252.2 MB
// 2023.1.13 at 奥盛大厦