class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    deque<vector<int>> dq;
    dq.push_back(newInterval);

    for (auto& i : intervals) {
      auto last = dq.back();
      dq.pop_back();

      if (i[1] < last[0]) {
        dq.push_back(i);
        dq.push_back(last);
      } else if (i[0] > last[1]) {
        dq.push_back(last);
        dq.push_back(i);
      } else {
        last[0] = min(last[0], i[0]);
        last[1] = max(last[1], i[1]);

        dq.push_back(last);
      }
    }

    return vector(dq.begin(), dq.end());
  }
};
// Runtime: 28 ms, faster than 85.93%
// Memory Usage: 18.3 MB, less than 7.08%

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    vector<vector<int>> ans;
    ans.push_back(newInterval);

    for (auto& i : intervals) {
      auto last = ans.back();
      ans.pop_back();

      if (i[1] < last[0]) {
        ans.push_back(i);
        ans.push_back(last);
      } else if (i[0] > last[1]) {
        ans.push_back(last);
        ans.push_back(i);
      } else {
        last[0] = min(last[0], i[0]);
        last[1] = max(last[1], i[1]);

        ans.push_back(last);
      }
    }

    return ans;
  }
};
// Runtime: 32 ms, faster than 66.63%
// Memory Usage: 18.1 MB, less than 8.55%