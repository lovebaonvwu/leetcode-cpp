class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& A) {
    sort(A.begin(), A.end());

    unordered_map<int, int> mp;

    for (int i = 0; i < A.size(); ++i) {
      mp[A[i]] = i;
    }

    vector<long> dp(A.size(), 1);

    for (int i = 1; i < A.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        if (A[i] % A[j] == 0 && mp.find(A[i] / A[j]) != mp.end()) {
          dp[i] += (dp[j] * dp[mp[A[i] / A[j]]]) % 1000000007;
        }
      }
    }

    int ans = 0;
    for (auto cnt : dp) {
      ans = (ans + cnt) % 1000000007;
    }

    return ans;
  }
};
// Runtime: 48 ms, faster than 93.80%
// Memory Usage: 9.3 MB, less than 68.22%

class Solution {
 public:
  int numFactoredBinaryTrees(vector<int>& A) {
    sort(A.begin(), A.end());

    unordered_map<int, long> dp;

    int ans = 0;
    for (int i = 0; i < A.size(); ++i) {
      dp[A[i]] = 1;

      for (int j = 0; j < i; ++j) {
        if (A[i] % A[j] == 0) {
          dp[A[i]] += dp[A[j]] * dp[A[i] / A[j]] % 1000000007;
        }
      }

      ans = (ans + dp[A[i]]) % 1000000007;
    }

    return ans;
  }
};
// Runtime: 84 ms, faster than 48.06%
// Memory Usage: 16.8 MB, less than 12.40%