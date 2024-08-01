class Solution {
 public:
  vector<string> validStrings(int n) {
    if (n == 1) {
      return {"0", "1"};
    }

    vector<string> prev = validStrings(n - 1);
    vector<string> ans;
    for (auto& p : prev) {
      ans.push_back(p + "1");
      if (p.back() == '1') {
        ans.push_back(p + "0");
      }
    }

    return ans;
  }
};
// 9 ms
// 17.51 MB