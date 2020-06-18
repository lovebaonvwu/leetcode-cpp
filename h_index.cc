class Solution {
 public:
  int hIndex(vector<int>& citations) {
    int n = citations.size();
    vector<int> cnt(n + 1);

    for (int c : citations) {
      if (c > n) {
        ++cnt[n];
      } else {
        ++cnt[c];
      }
    }

    int sum = 0;
    for (int i = cnt.size() - 1; i >= 0; --i) {
      sum += cnt[i];

      if (sum >= i) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 4 ms, faster than 90.91%
// Memory Usage: 9.1 MB, less than 5.39%