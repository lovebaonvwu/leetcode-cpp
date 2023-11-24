class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    if (A.empty()) {
      return 0;
    }

    int n = A.size();

    vector<int> diff(n - 1);

    for (int i = 1; i < A.size(); ++i) {
      diff[i - 1] = A[i] - A[i - 1];
    }

    int ans = 0;

    for (int i = 1, cnt = 0; i < n - 1; ++i) {
      if (diff[i] == diff[i - 1]) {
        ++cnt;

        ans += cnt;
      } else {
        cnt = 0;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 64.97%
// Memory Usage: 7.4 MB, less than 65.48%

class Solution {
 public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int ans = 0;

    for (int i = 1, cnt = 0; i < (int)A.size() - 1; ++i) {
      if (A[i + 1] - A[i] == A[i] - A[i - 1]) {
        ++cnt;

        ans += cnt;
      } else {
        cnt = 0;
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 64.97%
// Memory Usage: 7.3 MB, less than 65.48%