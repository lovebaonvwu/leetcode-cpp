class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    return dfs(cardPoints, k, 0, cardPoints.size() - 1);
  }

  int dfs(vector<int>& cardPoints, int k, int l, int r) {
    if (k == 0) {
      return 0;
    }

    int pl = dfs(cardPoints, k - 1, l + 1, r) + cardPoints[l];
    int pr = dfs(cardPoints, k - 1, l, r - 1) + cardPoints[r];

    return max(pl, pr);
  }
};
// Time Limit Exceeded

class Solution {
  vector<vector<int>> mem;

 public:
  int maxScore(vector<int>& cardPoints, int k) {
    mem =
        vector<vector<int>>(cardPoints.size(), vector<int>(cardPoints.size()));

    return dfs(cardPoints, k, 0, cardPoints.size() - 1);
  }

  int dfs(vector<int>& cardPoints, int k, int l, int r) {
    if (k == 0) {
      return 0;
    }

    if (mem[l][r] > 0) {
      return mem[l][r];
    }

    int pl = dfs(cardPoints, k - 1, l + 1, r) + cardPoints[l];
    int pr = dfs(cardPoints, k - 1, l, r - 1) + cardPoints[r];

    return mem[l][r] = max(pl, pr);
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    int leftSum = accumulate(cardPoints.begin(), cardPoints.begin() + k, 0);
    int rightSum = 0;

    size_t n = cardPoints.size();
    int ans = leftSum;
    for (int i = n - 1, j = 0; i >= n - k && j < n; --i, ++j) {
      leftSum -= cardPoints[k - 1 - j];
      rightSum += cardPoints[i];

      ans = max(ans, leftSum + rightSum);
    }

    return ans;
  }
};
// Runtime: 140 ms, faster than 91.90%
// Memory Usage: 42.7 MB, less than 100.00%

class Solution {
 public:
  int maxScore(vector<int>& cardPoints, int k) {
    vector<int> dp(k + 1);

    dp[0] = accumulate(cardPoints.rbegin(), cardPoints.rbegin() + k, 0);

    int ans = dp[0];

    size_t n = cardPoints.size();
    for (int i = 1; i <= k; ++i) {
      dp[i] = dp[i - 1] + cardPoints[i - 1] - cardPoints[n - k - 1 + i];
      ans = max(ans, dp[i]);
    }

    return ans;
  }
};
// Runtime: 144 ms, faster than 87.18%
// Memory Usage: 43.4 MB, less than 100.00%