class Solution {
 public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    auto idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();

    int i = idx - 1;
    int j = idx;

    while (k-- > 0) {
      if (i < 0 || j < arr.size() && (abs(arr[i] - x) > abs(arr[j] - x))) {
        ++j;
      } else {
        --i;
      }
    }

    return vector<int>(arr.begin() + i + 1, arr.begin() + j);
  }
};
// Runtime: 100 ms, faster than 73.06%
// Memory Usage: 13 MB, less than 66.67%