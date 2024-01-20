class Solution {
 public:
  vector<int> circularGameLosers(int n, int k) {
    vector<bool> visited(n);
    int cnt = 1;
    int cur = 0;
    while (true) {
      if (visited[cur]) {
        break;
      }

      visited[cur] = true;
      cur += cnt * k;
      cur %= n;
      ++cnt;
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        ans.push_back(i + 1);
      }
    }

    return ans;
  }
};
// 7 ms
// 10.92 MB