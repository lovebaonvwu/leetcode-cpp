class Solution {
 public:
  int minCostToMoveChips(vector<int>& chips) {
    vector<int> cnt(2);

    for (int i = 0; i < chips.size(); ++i) {
      ++cnt[chips[i] & 1];
    }

    return min(cnt[0], cnt[1]);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 100.00%