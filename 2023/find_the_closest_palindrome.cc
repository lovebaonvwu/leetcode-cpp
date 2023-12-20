class Solution {
 public:
  string nearestPalindromic(string n) {
    string smaller = nextSmaller(n);
    string greater = nextGreater(n);
    if (stoll(n) - stoll(smaller) <= stoll(greater) - stoll(n))
      return smaller;
    return greater;
  }

  string nextSmaller(string s) {
    int n = s.size();
    string t = s;
    for (int i = 0, j = n - 1; i <= j;)
      t[j--] = t[i++];
    if (t < s)
      return t;

    int carry = 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
      int d = s[i] - '0' - carry;
      if (d >= 0) {
        s[i] = d + '0';
        carry = 0;
      } else {
        s[i] = '9';
      }

      s[n - 1 - i] = s[i];
    }

    if (s[0] == '0' && n > 1) {
      return string(n - 1, '9');
    }

    return s;
  }

  string nextGreater(string s) {
    int n = s.size();
    string t = s;

    for (int i = 0, j = n - 1; i <= j;)
      t[j--] = t[i++];

    if (t > s)
      return t;

    int carry = 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
      int d = s[i] - '0' + carry;
      if (d <= 9) {
        s[i] = d + '0';
        carry = 0;
      } else {
        s[i] = '0';
      }

      s[n - 1 - i] = s[i];
    }

    if (carry) {
      s = string(n + 1, '0');
      s[0] = s[n] = '1';
    }

    return s;
  }
};
// 0ms
// 6.53MB