class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();
    vector<int> presum(n + 1);

    for (int i = 1; i < n + 1; ++i) {
      presum[i] = presum[i - 1] + code[i - 1];
    }

    vector<int> ans(n);
    if (k == 0) {
      return ans;
    }

    for (int i = 0; i < n; ++i) {
      if (k > 0) {
        if (i + k < n) {
          ans[i] = presum[i + k + 1] - presum[i + 1];
        } else {
          ans[i] = presum[n] - presum[i + 1];
          ans[i] += presum[k - (n - i - 1)];
        }
      } else {
        if (i + k >= 0) {
          ans[i] = presum[i] - presum[i + k];
        } else {
          ans[i] = presum[i];
          ans[i] += presum[n] - presum[n - (-k - (i + 1)) - 1];
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 72.11%
// Memory Usage: 8.3 MB, less than 94.80%

class Solution {
 public:
  vector<int> decrypt(vector<int>& code, int k) {
    int n = code.size();

    vector<int> ans(n);

    if (k == 0) {
      return ans;
    }

    bool reversed = false;
    if (k < 0) {
      reversed = true;
      k = -k;
      reverse(code.begin(), code.end());
    }

    int sum = 0;

    for (int i = 1; i <= k; ++i) {
      sum += code[i];
    }

    for (int i = 0; i < n; ++i) {
      ans[i] = sum;

      sum += code[(i + 1 + k) % n];
      sum -= code[(i + 1) % n];
    }

    if (reversed) {
      reverse(ans.begin(), ans.end());
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.1 MB, less than 98.13%