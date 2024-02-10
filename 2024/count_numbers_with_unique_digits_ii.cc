class Solution {
 public:
  int numberCount(int a, int b) {
    int ans = 0;
    for (int i = a; i <= b; ++i) {
      vector<bool> dup(10);
      bool nodup = true;
      int n = i;
      while (n > 0) {
        if (dup[n % 10]) {
          nodup = false;
          break;
        }
        dup[n % 10] = true;
        n /= 10;
      }

      ans += nodup;
    }

    return ans;
  }
};
// 34 ms
// 16.01 MB