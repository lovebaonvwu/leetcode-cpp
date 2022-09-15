class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    vector<pair<int, int>> line;
    for (auto& interval : intervals) {
      line.push_back({interval[0], 1});
      line.push_back({interval[1] + 1, -1});
    }

    sort(begin(line), end(line));

    int ans = 0;
    int cur = 0;
    for (auto it = line.begin(); it != line.end(); ++it) {
      ans = max(ans, cur += it->second);
    }

    return ans;
  }
};
// Runtime: 759 ms, faster than 79.04%
// Memory Usage: 98.6 MB, less than 55.85%
// 2022.9.15 at 奥盛大厦

class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> pq;

    for (auto i : intervals) {
      if (!pq.empty() && i[0] > pq.top()) {
        pq.pop();
      }

      pq.push(i[1]);
    }

    return pq.size();
  }
};
// Runtime: 937 ms, faster than 66.33%
// Memory Usage: 101.1 MB, less than 47.96%
// 2022.9.15 at 奥盛大厦