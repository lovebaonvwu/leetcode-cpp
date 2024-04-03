class Solution {
 public:
  int minimumLevels(vector<int>& possible) {
    int n = possible.size();
    vector<int> prefix(n);
    prefix[0] = possible[0] == 0 ? -1 : 1;
    vector<int> suffix(n);
    suffix[n - 1] = possible[n - 1] == 0 ? -1 : 1;

    for (int i = 1, j = n - 2; i < n; ++i, --j) {
      prefix[i] = prefix[i - 1] + (possible[i] == 0 ? -1 : 1);
      suffix[j] = suffix[j + 1] + (possible[j] == 0 ? -1 : 1);
    }

    int ans = -1;
    for (int i = 0; i < n - 1; ++i) {
      if (prefix[i] > suffix[i + 1]) {
        ans = i;
        break;
      }
    }

    return ans == -1 ? ans : ans + 1;
  }
};
// 229 ms
// 284.17 MB