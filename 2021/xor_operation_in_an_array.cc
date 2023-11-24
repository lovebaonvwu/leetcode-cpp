class Solution {
 public:
  int xorOperation(int n, int start) {
    vector<int> nums(n);

    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans ^= (start + 2 * i);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 100.00%