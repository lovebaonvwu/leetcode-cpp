class Solution {
 public:
  long long countCompleteDayPairs(vector<int>& hours) {
    long long ans = 0;
    unordered_map<int, long long> mp;
    for (auto h : hours) {
      ans += mp[(24 - h % 24) % 24];
      ++mp[h % 24];
    }

    return ans;
  }
};
// 158 ms
// 139.55 MB