class Solution {
 public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int n = growTime.size();

    vector<pair<int, int>> time(n);

    for (int i = 0; i < n; ++i) {
      time[i] = {growTime[i], plantTime[i]};
    }

    sort(begin(time), end(time), greater<pair<int, int>>());

    int ans = 0, cur = 0;

    for (auto& [g, p] : time) {
      ans = max(ans, cur + g + p);
      cur += p;
    }

    return ans;
  }
};
// Runtime: 220 ms, faster than 98.12%
// Memory Usage: 158.7 MB, less than 72.13%
// 2022.1.12 at 奥盛大厦