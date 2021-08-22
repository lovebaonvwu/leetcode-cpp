class Solution {
 public:
  int rectangleArea(vector<vector<int>>& rectangles) {
    vector<vector<int>> lines;

    for (auto& r : rectangles) {
      lines.push_back({r[1], r[0], r[2], 1});
      lines.push_back({r[3], r[0], r[2], 0});
    }

    sort(lines.begin(), lines.end());

    int prev_y = 0, prev_x = 0;
    long long sum = 0;
    int mod = 1e9 + 7;

    multiset<vector<int>> segments;

    long long ans = 0;

    for (auto& line : lines) {
      int y = line[0], x1 = line[1], x2 = line[2], newline = line[3];

      ans = (ans + (y - prev_y) * sum) % mod;

      prev_y = y;

      if (newline) {
        segments.insert({x1, x2});
      } else {
        segments.erase(segments.find({x1, x2}));
      }

      sum = 0;
      prev_x = 0;

      for (auto& segment : segments) {
        x1 = segment[0];
        x2 = segment[1];

        sum += max(0, x2 - max(x1, prev_x));
        prev_x = max(x2, prev_x);
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 87.65%
// Memory Usage: 8.9 MB, less than 78.19%
// 2021.8.22 at 奥盛大厦