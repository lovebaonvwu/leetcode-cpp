class Solution {
 public:
  vector<string> divideString(string s, int k, char fill) {
    vector<string> ans;

    for (int i = 0; i < s.size(); i += k) {
      ans.push_back(s.substr(i, k));
    }

    if (ans.back().size() < k) {
      ans.back().append(k - ans.back().size(), fill);
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.9 MB, less than 62.94%
// 2022.1.18 at 奥盛大厦