class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> mp;

    for (auto& n : deck) {
      mp[n]++;
    }

    int res = 0;

    for (auto& m : mp) {
      res = gcd(res, m.second);
    }

    return res > 1;
  }
};
// Runtime: 16 ms, faster than 78.28%
// Memory Usage: 9.8 MB, less than 75.00%

class Solution {
 public:
  bool hasGroupsSizeX(vector<int>& deck) {
    unordered_map<int, int> mp;

    for (auto& n : deck) {
      mp[n]++;
    }

    int res = 0;

    for (auto& m : mp) {
      res = mygcd(res, m.second);
    }

    return res > 1;
  }

  int mygcd(int a, int b) {
    if (b == 0) {
      return a;
    }

    return mygcd(b, a % b);
  }
};
// Runtime: 16 ms, faster than 78.28%
// Memory Usage: 9.7 MB, less than 100.00%