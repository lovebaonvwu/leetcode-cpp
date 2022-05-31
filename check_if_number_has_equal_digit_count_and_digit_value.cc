class Solution {
 public:
  bool digitCount(string num) {
    unordered_map<int, int> mp;

    for (auto ch : num) {
      ++mp[ch - '0'];
    }

    for (int i = 0; i < num.size(); ++i) {
      if (mp[i] != (num[i] - '0')) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 7 ms, faster than 17.44%
// Memory Usage: 6.2 MB, less than 7.97%
// 2022.5.31 at 奥盛大厦