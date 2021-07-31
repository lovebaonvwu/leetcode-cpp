class Solution {
 public:
  string maximumNumber(string num, vector<int>& change) {
    int n = num.size();
    bool changed = false;

    for (int i = 0; i < n; ++i) {
      if (change[num[i] - '0'] == (num[i] - '0')) {
        continue;
      }

      if (change[num[i] - '0'] > (num[i] - '0')) {
        num[i] = change[num[i] - '0'] + '0';
        changed = true;
      } else {
        if (changed) {
          break;
        }
      }
    }

    return num;
  }
};
// Runtime: 68 ms, faster than 74.46%
// Memory Usage: 28.8 MB, less than 48.84%
// 2021.7.31 at 奥盛大厦