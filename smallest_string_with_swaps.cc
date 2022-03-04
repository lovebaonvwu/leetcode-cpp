class Solution {
  int find(vector<int>& parents, int child) {
    if (parents[child] != child) {
      parents[child] = find(parents, parents[child]);
    }

    return parents[child];
  }

 public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();

    vector<int> parents(n);

    for (int i = 0; i < n; ++i) {
      parents[i] = i;
    }

    for (auto& p : pairs) {
      int i = find(parents, p[0]);
      int j = find(parents, p[1]);

      if (i != j) {
        parents[i] = j;
      }
    }

    unordered_map<int, vector<int>> mp;

    for (int i = 0; i < parents.size(); ++i) {
      mp[find(parents, i)].push_back(i);
    }

    for (auto& m : mp) {
      string ss = "";

      for (auto idx : m.second) {
        ss += s[idx];
      }

      sort(ss.begin(), ss.end());

      for (int i = 0; i < m.second.size(); ++i) {
        s[m.second[i]] = ss[i];
      }
    }

    return s;
  }
};
// Runtime: 212 ms, faster than 70.13%
// Memory Usage: 48 MB, less than 87.38%
// 2022.3.4 at 奥盛大厦