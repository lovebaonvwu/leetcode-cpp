class Solution {
 public:
  int garbageCollection(vector<string>& garbage, vector<int>& travel) {
    int n = garbage.size();
    vector<int> presum(n);
    for (int i = 1; i < n; ++i) {
      presum[i] = presum[i - 1] + travel[i - 1];
    }

    int ans = 0;
    int G = 0, P = 0, M = 0;
    for (int i = 0; i < n; ++i) {
      ans += garbage[i].size();
      for (auto g : garbage[i]) {
        int& prev = g == 'G' ? G : g == 'M' ? M : P;
        ans += presum[i] - presum[prev];
        prev = i;
      }
    }

    return ans;
  }
};
// Runtime: 547 ms, faster than 16.09%
// Memory Usage: 103.8 MB, less than 33.79%
// 2022.8.30 at 奥盛大厦