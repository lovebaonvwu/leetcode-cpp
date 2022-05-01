class Solution {
 public:
  int minimumCardPickup(vector<int>& cards) {
    unordered_map<int, int> mp;

    int ans = INT_MAX;

    for (int i = 0; i < cards.size(); ++i) {
      if (mp.find(cards[i]) != mp.end()) {
        ans = min(ans, i - mp[cards[i]] + 1);
      }

      mp[cards[i]] = i;
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
// Runtime: 416 ms, faster than 40.00%
// Memory Usage: 115.2 MB, less than 40.00%
// 2022.5.1 at 茗筑美嘉