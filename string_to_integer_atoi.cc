class Solution {
 public:
  int myAtoi(string str) {
    auto i = str.cbegin();

    while (i != str.cend() && isspace(*i)) {
      ++i;
    }

    int sign = 1;
    if (i != str.cend() && *i == '+') {
      ++i;
    } else if (i != str.cend() && *i == '-') {
      sign = -1;
      ++i;
    }

    long ans = 0;

    while (i != str.cend() && isdigit(*i)) {
      ans = ans * 10 + (*i - '0');

      if (sign < 0 && -ans < INT_MIN) {
        return INT_MIN;
      } else if (sign > 0 && ans > INT_MAX) {
        return INT_MAX;
      }

      ++i;
    }

    return sign * ans;
  }
};  // 8ms

class Solution {
 public:
  int myAtoi(string str) {
    int i = 0;

    for (char& s : str) {
      if (!isspace(s)) {
        break;
      }

      ++i;
    }

    str = string(str.begin() + i, str.end());

    if (str.empty()) {
      return 0;
    }

    int sign = 0;
    if (str[0] == '-') {
      sign = 1;
      str = string(str.begin() + 1, str.end());
    } else if (str[0] == '+') {
      str = string(str.begin() + 1, str.end());
    }

    long ans = 0;

    for (char& s : str) {
      if (!isdigit(s)) {
        break;
      }

      ans = ans * 10 + (s - '0');

      if (sign && -ans < INT_MIN) {
        return INT_MIN;
      } else if (!sign && ans > INT_MAX) {
        return INT_MAX;
      }
    }

    return sign ? -ans : ans;
  }
};  // 8ms