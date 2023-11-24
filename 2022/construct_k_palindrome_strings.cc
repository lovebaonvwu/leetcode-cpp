class Solution {
 public:
  bool canConstruct(string s, int k) {
    bitset<26> cnt;
    for (auto c : s) {
      cnt.flip(c - 'a');
    }

    return cnt.count() <= k && s.length() >= k;
  }
};
// Runtime: 90 ms, faster than 20.06%
// Memory Usage: 12 MB, less than 51.25%
// 2022.9.22 at 奥盛大厦