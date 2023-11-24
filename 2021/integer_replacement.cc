class Solution {
  unordered_map<int, int> mp;

 public:
  int integerReplacement(int n) {
    if (n == 1) {
      mp[1] = 0;
    }

    if (mp.find(n) != mp.end()) {
      return mp[n];
    }

    if (n & 1) {
      mp[n] =
          1 + min(integerReplacement(n - 1), integerReplacement(n / 2 + 1) + 1);
    } else {
      mp[n] = 1 + integerReplacement(n / 2);
    }

    return mp[n];
  }
};
// Runtime: 4 ms, faster than 44.95%
// Memory Usage: 9.7 MB, less than 14.91%