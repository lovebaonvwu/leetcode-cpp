class Solution {
 public:
  double trimMean(vector<int>& arr) {
    sort(arr.begin(), arr.end());

    int p = arr.size() * 0.05;

    double sum = 0;
    for (int i = p; i < arr.size() - p; ++i) {
      sum += arr[i];
    }

    return sum / (arr.size() - 2 * p);
  }
};
// Runtime: 16 ms, faster than 81.62%
// Memory Usage: 9.8 MB, less than 99.84%