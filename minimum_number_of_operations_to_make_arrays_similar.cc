class Solution {
 public:
  long long makeSimilar(vector<int>& nums, vector<int>& target) {
    vector<vector<int>> A(2);
    vector<vector<int>> B(2);

    for (auto n : nums) {
      A[n % 2].push_back(n);
    }
    sort(A[0].begin(), A[0].end());
    sort(A[1].begin(), A[1].end());

    for (auto n : target) {
      B[n % 2].push_back(n);
    }

    sort(B[0].begin(), B[0].end());
    sort(B[1].begin(), B[1].end());

    long long ans = 0;
    for (int i = 0; i < A[0].size(); ++i) {
      ans += abs(A[0][i] - B[0][i]) / 2;
    }

    for (int i = 0; i < A[1].size(); ++i) {
      ans += abs(A[1][i] - B[1][i]) / 2;
    }

    return ans / 2;
  }
};
// Runtime: 570 ms, faster than 22.22%
// Memory Usage: 86.7 MB, less than 44.44%
// 2022.10.24 at 奥盛大厦