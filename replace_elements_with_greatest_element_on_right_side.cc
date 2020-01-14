class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int mx = -1;

    for (int i = arr.size() - 1, tmp = 0; i >= 0; --i) {
      tmp = arr[i];

      arr[i] = mx;

      mx = max(tmp, mx);
    }

    return arr;
  }
};
// Runtime: 48 ms, faster than 94.45%
// Memory Usage: 10.6 MB, less than 100.00%

class Solution {
 public:
  vector<int> replaceElements(vector<int>& arr) {
    int mx = arr[arr.size() - 1];

    arr[arr.size() - 1] = -1;

    for (int i = arr.size() - 2, tmp = 0; i >= 0; --i) {
      tmp = arr[i];

      arr[i] = mx;

      mx = max(tmp, mx);
    }

    return arr;
  }
};
// Runtime: 52 ms, faster than 76.57%
// Memory Usage: 10.5 MB, less than 100.00%