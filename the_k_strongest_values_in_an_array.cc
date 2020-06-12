class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    int m = arr[(arr.size() - 1) / 2];

    sort(arr.begin(), arr.end(), [m = m](int a, int b) {
      if (abs(a - m) == abs(b - m)) {
        return a > b;
      }

      return abs(a - m) > abs(b - m);
    });

    arr.resize(k);

    return arr;
  }
};
// Runtime: 960 ms, faster than 54.00%
// Memory Usage: 80.3 MB, less than 100.00%

class Solution {
 public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    sort(arr.begin(), arr.end());

    int m = arr[(arr.size() - 1) / 2];

    vector<int> ans;
    for (int i = 0, j = arr.size() - 1; k > 0 && i <= j; --k) {
      int si = abs(arr[i] - m);
      int sj = abs(arr[j] - m);

      if (si > sj) {
        ans.push_back(arr[i++]);
      } else {
        ans.push_back(arr[j--]);
      }
    }

    return ans;
  }
};
// Runtime: 504 ms, faster than 87.25%
// Memory Usage: 82.7 MB, less than 100.00%