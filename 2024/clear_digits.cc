class Solution {
 public:
  string clearDigits(string s) {
    vector<char> stk;
    for (auto c : s) {
      if (isdigit(c)) {
        stk.pop_back();
      } else {
        stk.push_back(c);
      }
    }

    string ans;
    for (auto c : stk) {
      ans += c;
    }

    return ans;
  }
};
// 2 ms
// 7.92 MB