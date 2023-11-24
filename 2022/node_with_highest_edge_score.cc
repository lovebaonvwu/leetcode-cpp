class Solution {
 public:
  int edgeScore(vector<int>& edges) {
    map<int, long long> mp;

    for (int i = 0; i < edges.size(); ++i) {
      mp[edges[i]] += i;
    }

    int ans = 0;
    int cnt = 0;
    for (auto& [n, val] : mp) {
      if (val > cnt) {
        cnt = val;
        ans = n;
      }
    }

    return ans;
  }
};
// Runtime: 727 ms, faster than 14.29%
// Memory Usage: 136.3 MB, less than 42.86%
// 2022.8.16 at 奥盛大厦