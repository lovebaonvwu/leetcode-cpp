class Solution {
 public:
  vector<int> pancakeSort(vector<int>& A) {
    vector<int> ans;

    int n = A.size();
    for (int i = n - 1; i >= 0; --i) {
      if (A[i] != i + 1) {
        for (int j = 0; j < i; ++j) {
          if (A[j] == i + 1) {
            ans.push_back(j + 1);
            reverse(A.begin(), A.begin() + j + 1);
            ans.push_back(i + 1);
            reverse(A.begin(), A.begin() + i + 1);
          }
        }
      }
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 95.99%
// Memory Usage: 11.2 MB, less than 61.39%