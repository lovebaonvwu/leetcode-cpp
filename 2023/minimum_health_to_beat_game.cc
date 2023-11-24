class Solution {
 public:
  long long minimumHealth(vector<int>& damage, int armor) {
    long long ans = accumulate(damage.begin(), damage.end(), 0L);
    ans = abs(ans);
    int maxDamage = *max_element(damage.begin(), damage.end());
    ans -= min(maxDamage, armor);

    return ans + 1;
  }
};
// Runtime 99 ms
// Memory 59.2 MB
// 2023.1.10 at 奥盛大厦