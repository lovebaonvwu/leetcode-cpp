class Solution {
 public:
  int largestInteger(int num) {
    vector<int> d;

    while (num > 0) {
      d.push_back(num % 10);
      num /= 10;
    }

    reverse(d.begin(), d.end());

    for (int i = 0; i < d.size(); ++i) {
      for (int j = i; j < d.size(); ++j) {
        if (d[i] < d[j]) {
          if (((d[i] & 1) && (d[j] & 1)) ||
              ((d[i] % 2 == 0) && (d[j] % 2 == 0))) {
            swap(d[i], d[j]);
          }
        }
      }
    }

    int ans = 0;
    for (int i = 0; i < d.size(); ++i) {
      ans = ans * 10 + d[i];
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 25.90%
// Memory Usage: 6 MB, less than 82.87%
// 2022.4.17 at 奥盛大厦