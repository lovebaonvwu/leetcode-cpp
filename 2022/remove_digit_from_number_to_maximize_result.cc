class Solution {
 public:
  string removeDigit(string number, char digit) {
    int offset = 0, pos = 0;

    string ans;
    while ((pos = number.find(digit, offset)) != std::string::npos) {
      string s = number.substr(0, pos) + number.substr(pos + 1);
      ans = max(ans, s);
      offset = pos + 1;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.9 MB, less than 39.11%
// 2022.5.28 at 奥盛大厦

class Solution {
 public:
  string removeDigit(string number, char digit) {
    for (int i = 0; i < number.size() - 1; ++i) {
      if (number[i] == digit && number[i] < number[i + 1]) {
        return number.substr(0, i) + number.substr(i + 1);
      }
    }

    auto pos = number.rfind(digit);
    return number.substr(0, pos) + number.substr(pos + 1);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 91.92%
// 2022.5.28 at 奥盛大厦