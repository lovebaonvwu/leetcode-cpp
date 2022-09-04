class Solution {
 public:
  bool checkDistances(string s, vector<int>& distance) {
    unordered_map<char, int> mp;

    for (int i = 0; i < s.size(); ++i) {
      if (mp.find(s[i]) != mp.end()) {
        if (i - mp[s[i]] - 1 != distance[s[i] - 'a']) {
          return false;
        }
      }

      mp[s[i]] = i;
    }

    return true;
  }
};
// Runtime: 11 ms, faster than 50.00%
// Memory Usage: 13.5 MB, less than 50.00%
// 2022.9.4 at 茗筑美嘉