class Solution {
 public:
  string decodeMessage(string key, string message) {
    unordered_map<char, char> mp;

    int cnt = 0;
    for (auto k : key) {
      if (k != ' ' && mp.find(k) == mp.end()) {
        mp[k] = 'a' + cnt++;
      }
    }

    string ans;
    for (auto m : message) {
      ans += m == ' ' ? ' ' : mp[m];
    }

    return ans;
  }
};
// Runtime: 9 ms, faster than 31.30%
// Memory Usage: 7.1 MB, less than 23.48%
// 2022.7.9 at 奥盛大厦