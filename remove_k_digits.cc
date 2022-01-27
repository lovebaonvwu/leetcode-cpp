class Solution {
 public:
  string removeKdigits(string num, int k) {
    string ans;

    for (auto n : num) {
      while (!ans.empty() && ans.back() > n && k > 0) {
        ans.pop_back();
        --k;
      }

      if (!ans.empty() || n != '0') {
        ans.push_back(n);
      }
    }

    while (!ans.empty() && k-- > 0) {
      ans.pop_back();
    }

    return ans.empty() ? "0" : ans;
  }
};
// Runtime: 9 ms, faster than 37.01%
// Memory Usage: 7 MB, less than 52.56%
// 2022.1.27 at 奥盛大厦