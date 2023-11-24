class Solution {
 public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int l = left.empty() ? 0 : *max_element(left.begin(), left.end());
    int r = right.empty() ? n : *min_element(right.begin(), right.end());

    return max(l, n - r);
  }
};
// Runtime: 24 ms, faster than 93.26%
// Memory Usage: 22.8 MB, less than 92.13%