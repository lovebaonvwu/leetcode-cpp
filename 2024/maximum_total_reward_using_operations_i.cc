class Solution {
  int ans = 0;
  int n;
  void dfs(vector<int>& rewardValues, int i, int total) {
    if (i == n) {
      ans = max(ans, total);
      return;
    }

    dfs(rewardValues, i + 1, total);
    if (rewardValues[i] > total) {
      dfs(rewardValues, i + 1, total + rewardValues[i]);
    }
  }

 public:
  int maxTotalReward(vector<int>& rewardValues) {
    sort(begin(rewardValues), end(rewardValues));
    n = rewardValues.size();
    dfs(rewardValues, 0, 0);

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxTotalReward(vector<int>& rewardValues) {
    sort(begin(rewardValues), end(rewardValues));
    int n = rewardValues.size();
    vector<vector<int>> cached(n, vector<int>(4001, -1));
    function<int(int, int)> dfs = [&](int i, int total) -> int {
      if (i == n) {
        return 0;
      }

      if (cached[i][total] != -1)
        return cached[i][total];

      int ret = 0;
      if (rewardValues[i] > total) {
        ret = max(ret, rewardValues[i] + dfs(i + 1, total + rewardValues[i]));
      }

      ret = max(ret, dfs(i + 1, total));

      return cached[i][total] = ret;
    };
    return dfs(0, 0);
  }
};
// 1295 ms
// 346.24 MB
