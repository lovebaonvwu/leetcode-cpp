class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int gs = groupSizes.size();
    vector<vector<int>> groups(gs + 1);
    vector<vector<int>> ans;

    for (int i = 0; i < gs; ++i) {
      groups[groupSizes[i]].push_back(i);

      if (groups[groupSizes[i]].size() == groupSizes[i]) {
        ans.push_back(groups[groupSizes[i]]);
        groups[groupSizes[i]].clear();
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 98.02%
// Memory Usage: 11.9 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> groups(groupSizes.size() + 1);

    for (int i = 0; i < groupSizes.size(); ++i) {
      groups[groupSizes[i]].push_back(i);
    }

    vector<vector<int>> ans;

    for (int i = 0; i < groups.size(); ++i) {
      if (groups[i].size() > 0) {
        for (int j = 0; j < groups[i].size(); j += i) {
          vector<int> g(groups[i].begin() + j, groups[i].begin() + j + i);
          ans.push_back(g);
        }
      }
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 86.88%
// Memory Usage: 12.7 MB, less than 100.00%

class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    int gs = groupSizes.size();
    vector<vector<int>> groups(gs + 1);
    vector<vector<int>> ans;

    for (int i = 0; i < gs; ++i) {
      groups[groupSizes[i]].push_back(i);

      if (groups[groupSizes[i]].size() == groupSizes[i]) {
        ans.push_back({});
        swap(groups[groupSizes[i]], ans.back());
      }
    }

    return ans;
  }
};
// Runtime: 28 ms, faster than 55.50%
// Memory Usage: 12 MB, less than 100.00%