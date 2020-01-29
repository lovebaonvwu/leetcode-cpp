class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> ans;

    for (int i = 0, n = 0; i < A.size(); ++i) {
      n = (n * 2 + A[i]) % 5;

      ans.push_back(!n);
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 89.42%
// Memory Usage: 10.8 MB, less than 78.57%

class Solution {
 public:
  vector<bool> prefixesDivBy5(vector<int>& A) {
    vector<bool> ans(A.size(), false);

    int n = 0;
    for (int i = 0; i < A.size(); ++i) {
      n = (n % 5) * 2 + A[i];

      if (n % 5 == 0) {
        ans[i] = true;
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 89.42%
// Memory Usage: 10.8 MB, less than 71.43%