class Solution {
 public:
  int romanToInt(string s) {
    int ans = 0;

    for (int i = s.size() - 1; i >= 0; --i) {
      switch (s[i]) {
        case 'I':
          ans += ans >= 5 ? -1 : 1;
          break;
        case 'V':
          ans += 5;
          break;
        case 'X':
          ans += ans >= 50 ? -10 : 10;
          break;
        case 'L':
          ans += 50;
          break;
        case 'C':
          ans += ans >= 500 ? -100 : 100;
          break;
        case 'D':
          ans += 500;
          break;
        case 'M':
          ans += 1000;
          break;
      }
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  int romanToInt(string s) {
    unordered_map<string, int> mp({{"I", 1},
                                   {"II", 2},
                                   {"III", 3},
                                   {"IV", 4},
                                   {"V", 5},
                                   {"IX", 9},
                                   {"X", 10},
                                   {"XL", 40},
                                   {"L", 50},
                                   {"XC", 90},
                                   {"C", 100},
                                   {"CD", 400},
                                   {"D", 500},
                                   {"CM", 900},
                                   {"M", 1000}});

    string sym = "";
    sym += s[0];

    int ans = 0;

    for (int i = 1; i < s.size(); ++i) {
      string tmp = sym + s[i];

      if (!mp[tmp]) {
        ans += mp[sym];
        sym = "";
        sym += s[i];
      } else {
        sym = tmp;
      }
    }

    if (!sym.empty()) {
      ans += mp[sym];
    }

    return ans;
  }
};  // 40ms