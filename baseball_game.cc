class Solution {
 public:
  int calPoints(vector<string>& ops) {
    vector<int> stk;

    for (auto& s : ops) {
      if (s == "C") {
        stk.pop_back();
      } else if (s == "D") {
        stk.push_back(stk.back() * 2);
      } else if (s == "+") {
        int a = stk.back();
        int b = stk[stk.size() - 2];

        stk.push_back(a + b);
      } else {
        stk.push_back(std::stoi(s));
      }
    }

    int ans = 0;

    for (auto n : stk) {
      ans += n;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 75.51%
// Memory Usage: 8.3 MB, less than 94.34%
// 2021.12.25 at 奥盛大厦