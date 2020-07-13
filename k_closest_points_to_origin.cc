class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    unordered_map<int, vector<int>> mp;
    priority_queue<int, vector<int>, greater<int>> q;

    for (int i = 0; i < points.size(); ++i) {
      int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];

      mp[d].push_back(i);

      q.push(d);
    }

    vector<vector<int>> ans;

    while (!q.empty() && K-- > 0) {
      int d = q.top();
      q.pop();

      auto& i = mp[d].back();
      mp[d].pop_back();

      ans.push_back(points[i]);
    }

    return ans;
  }
};
// Runtime: 652 ms, faster than 23.19%
// Memory Usage: 70.7 MB, less than 21.84%

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    unordered_map<int, vector<int>> mp;
    vector<int> q;

    for (int i = 0; i < points.size(); ++i) {
      int d = points[i][0] * points[i][0] + points[i][1] * points[i][1];

      mp[d].push_back(i);

      q.push_back(d);
    }

    sort(q.begin(), q.end());

    vector<vector<int>> ans;

    for (int i = 0; i < q.size() && K > 0; ++i, --K) {
      int idx = mp[q[i]].back();
      mp[q[i]].pop_back();

      ans.push_back(points[idx]);
    }

    return ans;
  }
};
// Runtime: 536 ms, faster than 35.02%
// Memory Usage: 71 MB, less than 21.50%

class Solution {
 public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    nth_element(points.begin(), points.begin() + K - 1, points.end(),
                [](auto& a, auto& b) {
                  return a[0] * a[0] + a[1] * a[1] < b[0] * b[0] + b[1] * b[1];
                });

    return vector(points.begin(), points.begin() + K);
  }
};
// Runtime: 276 ms, faster than 96.79%
// Memory Usage: 49.2 MB, less than 96.92%