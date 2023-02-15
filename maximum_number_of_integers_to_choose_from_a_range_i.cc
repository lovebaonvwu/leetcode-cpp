class Solution {
 public:
  int maxCount(vector<int>& banned, int n, int maxSum) {
    sort(banned.begin(), banned.end());

    int ans = 0;
    int sum = 0;
    int cur = 1;

    for (int i = 0; i < banned.size() && cur <= n;) {
      if (cur < banned[i]) {
        sum += cur++;
        if (sum <= maxSum) {
          ++ans;
        } else {
          break;
        }
      } else {
        cur = banned[i] + 1;
        ++i;
      }
    }

    while (sum <= maxSum && cur <= n) {
      sum += cur++;
      if (sum <= maxSum) {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime 307 ms
// Memory 113.7 MB
// 2023.2.15 at 奥盛大厦