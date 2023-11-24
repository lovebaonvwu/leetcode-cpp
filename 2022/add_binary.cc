class Solution {
 public:
  string addBinary(string a, string b) {
    int a_len = a.size() - 1;
    int b_len = b.size() - 1;
    char sum = 0;

    string ans;

    while (a_len >= 0 || b_len >= 0 || sum) {
      sum += a_len >= 0 ? a[a_len] - '0' : 0;
      sum += b_len >= 0 ? b[b_len] - '0' : 0;

      ans = char(sum % 2 + '0') + ans;
      sum /= 2;

      --a_len;
      --b_len;
    }

    return ans;
  }
};  // 4ms

class Solution {
 public:
  string addBinary(string a, string b) {
    int a_len = a.size() - 1;
    int b_len = b.size() - 1;
    char carry = 0;

    string ans;

    while (a_len >= 0 || b_len >= 0 || carry) {
      char a_val = a_len >= 0 ? a[a_len] : '0';
      char b_val = b_len >= 0 ? b[b_len] : '0';

      a_val -= 48;
      b_val -= 48;

      char val = a_val + b_val + carry;
      carry = val / 2;
      val = val % 2;

      val += 48;

      ans = val + ans;

      --a_len;
      --b_len;
    }

    return ans;
  }
};  // 8ms