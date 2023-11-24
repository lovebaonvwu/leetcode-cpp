class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int i = INT_MAX;
    int j = INT_MAX;

    for (int& n : nums) {
      if (n <= i) {
        i = n;
      } else if (n <= j) {
        j = n;
      } else {
        return true;
      }
    }

    return false;
  }
};
// Runtime: 4 ms, faster than 96.97%
// Memory Usage: 8.9 MB, less than 100.00%