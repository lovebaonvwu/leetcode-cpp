class Solution {
 public:
  string multiply(string num1, string num2) {
    if (num1 == "0" || num2 == "0") {
      return "0";
    }

    vector<string> tmp(num2.size(), "");

    for (int i = num2.size() - 1, k = 0; i >= 0; --i, ++k) {
      int op2 = num2[i] - '0';
      int add = 0;

      for (int j = num1.size() - 1; j >= 0; --j) {
        int op1 = num1[j] - '0';

        int multi = op1 * op2 + add;

        add = multi / 10;
        multi %= 10;

        tmp[k] = string(to_string(multi)) + tmp[k];
      }

      if (add) {
        tmp[k] = to_string(add) + tmp[k];
      }

      tmp[k].append(k, '0');
    }

    for (int k = 1; k < tmp.size(); ++k) {
      int i = tmp[k - 1].size() - 1, j = tmp[k].size() - 1, add = 0;

      while (i >= 0 || j >= 0) {
        int op1 = i >= 0 ? tmp[k - 1][i] - '0' : 0;
        int op2 = j >= 0 ? tmp[k][j] - '0' : 0;

        int sum = op1 + op2 + add;

        add = sum / 10;

        tmp[k][j] = (sum % 10) + '0';

        --i, --j;
      }

      if (add) {
        tmp[k] = "1" + tmp[k];
      }
    }

    return tmp.back();
  }
};
// Runtime: 72 ms
// Memory Usage: 23.5 MB
// 2021.11.7 at 茗筑美嘉

class Solution {
 public:
  string multiply(string num1, string num2) {
    int n1 = num1.size(), n2 = num2.size();

    string s(n1 + n2, '0');

    for (int i = n1 - 1; i >= 0; --i) {
      int carry = 0;

      for (int j = n2 - 1; j >= 0; --j) {
        int sum =
            (s[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
        s[i + j + 1] = sum % 10 + '0';

        carry = sum / 10;
      }

      s[i] += carry;
    }

    auto pos = s.find_first_not_of("0");

    if (pos == string::npos) {
      return "0";
    }

    return s.substr(pos);
  }
};
// Runtime: 4 ms, faster than 90.06%
// Memory Usage: 6.6 MB, less than 70.82%
// 2021.11.7 at 茗筑美嘉