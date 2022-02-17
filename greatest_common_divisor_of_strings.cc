class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    return str1 + str2 == str2 + str1
               ? str1.substr(0, gcd(str1.size(), str2.size()))
               : "";
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 7.1 MB, less than 78.05%
// 2022.2.17 at 奥盛大厦

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.size() < str2.size()) {
      return gcdOfStrings(str2, str1);
    }
    if (str2.empty()) {
      return str1;
    }
    if (str1.substr(0, str2.size()) != str2) {
      return "";
    }

    return gcdOfStrings(str1.substr(str2.size()), str2);
  }
};
// Runtime: 4 ms, faster than 69.98%
// Memory Usage: 8.4 MB, less than 18.79%
// 2022.2.17 at 奥盛大厦