class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    arr[0] = 1;

    for (int i = 1; i < arr.size(); ++i) {
      if (arr[i] > arr[i - 1]) {
        arr[i] = arr[i - 1] + 1;
      } else {
        arr[i] = arr[i - 1];
      }
    }

    return arr[arr.size() - 1];
  }
};
// Runtime: 96 ms, faster than 79.39%
// Memory Usage: 51.3 MB, less than 18.48%