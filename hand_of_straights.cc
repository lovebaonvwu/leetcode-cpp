class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    map<int, int> mp;

    for (auto h : hand) {
      ++mp[h];
    }

    for (auto [h, cnt] : mp) {
      if (cnt > 0) {
        for (int k = groupSize - 1; k >= 0; --k) {
          if (mp[h + k] < cnt) {
            return false;
          }

          mp[h + k] -= cnt;
        }
      }
    }

    return true;
  }
};
// Runtime: 84 ms, faster than 90.56%
// Memory Usage: 28.3 MB, less than 62.99%
// 2022.8.20 at 奥盛大厦