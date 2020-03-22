class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;

    for (auto n1 : arr1) {
      bool found = true;
      for (auto n2 : arr2) {
        if (abs(n1 - n2) <= d) {
          found = false;
          break;
        }
      }

      if (found) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 10.00%
// Memory Usage: 6.9 MB, less than 100.00%

class Solution {
 public:
  int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
    int ans = 0;

    for (auto n1 : arr1) {
      if (all_of(arr2.begin(), arr2.end(),
                 [n1, d](int n2) { return abs(n1 - n2) > d; })) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 36 ms, faster than 10.00%
// Memory Usage: 6.7 MB, less than 100.00%