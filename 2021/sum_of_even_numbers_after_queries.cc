class Solution {
 public:
  vector<int> sumEvenAfterQueries(vector<int>& A,
                                  vector<vector<int>>& queries) {
    vector<int> ans(A.size());

    int sum = 0;

    for (int& a : A) {
      if (a % 2 == 0) {
        sum += a;
      }
    }

    for (int i = 0; i < A.size(); ++i) {
      int tmp = A[queries[i][1]];
      A[queries[i][1]] += queries[i][0];

      if (A[queries[i][1]] % 2 == 0) {
        if (tmp % 2 == 0) {
          sum += queries[i][0];
        } else {
          sum += A[queries[i][1]];
        }
      } else {
        if (tmp % 2 == 0) {
          sum -= tmp;
        }
      }
      ans[i] = sum;
    }

    return ans;
  }
};