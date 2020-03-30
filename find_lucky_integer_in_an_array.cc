class Solution {
 public:
  int findLucky(vector<int>& arr) {
    unordered_map<int, int> mp;

    for (auto n : arr) {
      ++mp[n];
    }

    int ans = -1;

    for (auto it : mp) {
      if (it.first == it.second) {
        ans = max(ans, it.first);
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 28.57%
// Memory Usage: 10.6 MB, less than 100.00%