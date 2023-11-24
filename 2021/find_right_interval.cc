class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    vector<int> ans;

    for (int i = 0; i < intervals.size(); ++i) {
      int min_pos = -1;
      int min_left = INT_MAX;

      for (int j = 0; j < intervals.size(); ++j) {
        if (j != i && intervals[j][0] >= intervals[i][1] &&
            intervals[j][0] < min_left) {
          min_pos = j;
          min_left = intervals[j][0];
        }
      }

      ans.push_back(min_pos);
    }

    return ans;
  }
};
// Time Limit Exceeded

class Solution {
 public:
  vector<int> findRightInterval(vector<vector<int>>& intervals) {
    map<int, int> mp;

    for (int i = 0; i < intervals.size(); ++i) {
      if (!mp.count(intervals[i][0])) {
        mp[intervals[i][0]] = i;
      }
    }

    vector<int> ans;
    for (auto& i : intervals) {
      auto it = mp.lower_bound(i[1]);
      ans.push_back(it == mp.end() ? -1 : it->second);
    }

    return ans;
  }
};
// Runtime: 184 ms, faster than 61.78%
// Memory Usage: 28.4 MB, less than 44.01%