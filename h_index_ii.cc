class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();

    int i = 0;
    int j = n - 1;

    while (i <= j) {
      int mid = i + (j - i) / 2;

      if (citations[mid] > n - mid) {
        j = mid - 1;
      } else if (citations[mid] < n - mid) {
        i = mid + 1;
      } else {
        return n - mid;
      }
    }

    return n - i;
  }
};
// Runtime: 44 ms, faster than 47.92%
// Memory Usage: 18.8 MB, less than 37.26%