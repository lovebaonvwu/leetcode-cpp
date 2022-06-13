class Solution {
 public:
  vector<int> successfulPairs(vector<int>& spells,
                              vector<int>& potions,
                              long long success) {
    int n = spells.size();
    vector<int> ans(n);

    sort(potions.begin(), potions.end());

    for (int i = 0; i < spells.size(); ++i) {
      int lo = 0, hi = potions.size() - 1;
      long long spell = spells[i];

      while (lo < hi) {
        int md = lo + (hi - lo) / 2;
        if (spell * potions[md] < success) {
          lo = md + 1;
        } else {
          hi = md;
        }
      }

      if (spell * potions[lo] >= success) {
        ans[i] = potions.size() - lo;
      }
    }

    return ans;
  }
};
// Runtime: 305 ms, faster than 50.00%
// Memory Usage: 97.2 MB, less than 50.00%
// 2022.6.13 at 奥盛大厦