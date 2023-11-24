class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1 || n == 2) {
      return 1;
    }

    int tn = 0;
    int tn1 = 1;
    int tn2 = 1;

    int ans = 0;

    for (int i = 3; i <= n; ++i) {
      ans = tn + tn1 + tn2;
      tn = tn1;
      tn1 = tn2;
      tn2 = ans;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.2 MB, less than 100.00%

class Solution {
 public:
  int tribonacci(int n) {
    if (n == 0) {
      return 0;
    } else if (n == 1 || n == 2) {
      return 1;
    }

    int n0 = 0;
    int n1 = 1;
    int n2 = 1;

    int ans = 0;

    for (int i = 3; i <= n; ++i) {
      ans = n0 + n1 + n2;
      n0 = n1;
      n1 = n2;
      n2 = ans;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 51.26%
// Memory Usage: 8.2 MB, less than 100.00%