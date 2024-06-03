class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    sort(begin(meetings), end(meetings),
         [](auto& a, auto& b) { return a[0] < b[0]; });

    vector<int> prev = meetings[0];
    int ans = prev[0] - 1;
    for (int i = 1; i < meetings.size(); ++i) {
      if (prev[1] < meetings[i][0]) {
        ans += meetings[i][0] - prev[1] - 1;
        prev = meetings[i];
      } else {
        prev[1] = max(prev[1], meetings[i][1]);
      }
    }

    ans += days - prev[1];

    return ans;
  }
};
// 276 ms
// 125.51 MB