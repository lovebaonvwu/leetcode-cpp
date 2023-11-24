class Solution {
 public:
  int findSpecialInteger(vector<int>& arr) {
    int n = arr.size();
    int target = n / 4;
    int cnt = 1;

    for (int i = 1; i < n; ++i) {
      if (arr[i] != arr[i - 1]) {
        cnt = 1;
      } else {
        cnt += 1;
      }

      if (cnt > target) {
        return arr[i];
      }
    }

    return arr[0];
  }
};
// Runtime: 12 ms, faster than 98.15%
// Memory Usage: 9.3 MB, less than 100.00%