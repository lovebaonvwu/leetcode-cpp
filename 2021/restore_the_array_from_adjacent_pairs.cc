class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> mp;

    for (auto& p : adjacentPairs) {
      mp[p[0]].push_back(p[1]);
      mp[p[1]].push_back(p[0]);
    }

    int h;

    for (auto& m : mp) {
      if (m.second.size() == 1) {
        h = m.first;
        break;
      }
    }

    vector<int> ans;

    ans.push_back(h);

    while (ans.size() < adjacentPairs.size() + 1) {
      auto adj = mp[ans.back()];

      for (auto n : adj) {
        if (ans.size() == 1 || n != ans[ans.size() - 2]) {
          ans.push_back(n);
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 1108 ms, faster than 21.34%
// Memory Usage: 113.6 MB, less than 78.31%

class Solution {
 public:
  vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
    unordered_map<int, vector<int>> mp;

    for (auto& p : adjacentPairs) {
      mp[p[0]].push_back(p[1]);
      mp[p[1]].push_back(p[0]);
    }

    vector<int> ans;

    for (auto& m : mp) {
      if (m.second.size() == 1) {
        ans.push_back(m.first);
        break;
      }
    }

    while (ans.size() < adjacentPairs.size() + 1) {
      auto adj = mp[ans.back()];

      for (auto n : adj) {
        if (ans.size() == 1 || n != ans[ans.size() - 2]) {
          ans.push_back(n);
          break;
        }
      }
    }

    return ans;
  }
};
// Runtime: 564 ms, faster than 80.23%
// Memory Usage: 113.5 MB, less than 78.95%