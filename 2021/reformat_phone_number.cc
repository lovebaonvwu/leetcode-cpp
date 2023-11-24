class Solution {
 public:
  string reformatNumber(string number) {
    string s;

    for (auto c : number) {
      if (isdigit(c)) {
        s += c;
      }
    }

    int n = s.size();

    string ans;

    int i = 0;

    for (; i < n - 4; i += 3) {
      ans += s.substr(i, 3);
      ans += '-';
    }

    if (n - i < 4) {
      ans += s.substr(i);
    } else {
      ans += s.substr(i, 2);
      ans += '-';
      i += 2;
      ans += s.substr(i);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 77.09%
// 2021.8.20 at 奥盛大厦