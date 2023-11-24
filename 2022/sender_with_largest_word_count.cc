class Solution {
 public:
  string largestWordCount(vector<string>& messages, vector<string>& senders) {
    int n = messages.size();

    unordered_map<string, int> mp;

    for (int i = 0; i < n; ++i) {
      int cnt = count(messages[i].begin(), messages[i].end(), ' ');
      mp[senders[i]] += cnt + 1;
    }

    string ans;
    int w = 0;

    for (auto& m : mp) {
      if (m.second > w) {
        w = m.second;
        ans = m.first;
      } else if (m.second == w) {
        ans = max(ans, m.first);
      }
    }

    return ans;
  }
};
// Runtime: 180 ms, faster than 100.00%
// Memory Usage: 71.9 MB, less than 50.00%
// 2022.5.30 at 奥盛大厦