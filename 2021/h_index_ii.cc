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
    for (int i = n; i >= 0; --i) {
      sum += cnt[i];

      if (sum >= i) {
        return i;
      }
    }

    return -1;
  }
};
// Runtime: 44 ms, faster than 47.92%
// Memory Usage: 19.6 MB, less than 5.36%