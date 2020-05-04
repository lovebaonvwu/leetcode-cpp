class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_set<string> s1, s2;

    for (auto& path : paths) {
      s1.insert(path[0]);
      s2.insert(path[1]);
    }

    string ans;
    for (auto& s : s2) {
      if (!s1.count(s)) {
        ans = s;
        break;
      }
    }

    return ans;
  }
};
// Runtime: 20 ms, faster than 99.01%
// Memory Usage: 11.3 MB, less than 100.00%

class Solution {
 public:
  string destCity(vector<vector<string>>& paths) {
    unordered_map<string, string> mp;

    for (auto& path : paths) {
      mp[path[0]] = path[1];
    }

    string ans = paths[0][1];
    while (mp.count(ans)) {
      ans = mp[ans];
    }

    return ans;
  }
};
// Runtime: 24 ms, faster than 95.05%
// Memory Usage: 10.9 MB, less than 100.00%