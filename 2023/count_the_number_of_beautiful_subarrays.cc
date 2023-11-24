class Solution {
 public:
  long long beautifulSubarrays(vector<int>& nums) {
    unordered_map<int, int> mp;
    mp[0] = 1;

    long long ans = 0LL;

    int prexor = 0;
    for (auto n : nums) {
      prexor ^= n;

      ans += mp[prexor]++;
    }

    return ans;
  }
};
// Runtime 344 ms
// Memory 120.4 MB