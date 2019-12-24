class Solution {
 public:
  string strWithout3a3b(int A, int B) {
    string ans;

    if (A > B) {
      ans = strWithout3a3b(A, B, 'a', 'b');
    } else {
      ans = strWithout3a3b(B, A, 'b', 'a');
    }

    return ans;
  }

  string strWithout3a3b(int A, int B, char a, char b) {
    string res;

    while (A-- > 0) {
      res += a;

      if (A > B) {
        res += a;
        --A;
      }

      if (B-- > 0) {
        res += b;
      }
    }

    return res;
  }
};
// Runtime: 4 ms, faster than 60.55%
// Memory Usage: 8.5 MB, less than 100.00%