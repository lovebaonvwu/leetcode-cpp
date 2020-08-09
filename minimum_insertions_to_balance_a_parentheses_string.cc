class Solution {
 public:
  int minInsertions(string s) {
    vector<char> stk;

    int ans = 0;

    for (auto ch : s) {
      if (ch == '(') {
        if (stk.empty() || stk.back() == '(') {
          stk.push_back(ch);
        } else {
          ++ans;

          stk.pop_back();
          stk.pop_back();

          stk.push_back(ch);
        }
      } else {
        if (stk.empty()) {
          ++ans;

          stk.push_back('(');
          stk.push_back(ch);
        } else if (stk.back() == '(') {
          stk.push_back(ch);
        } else {
          stk.pop_back();
          stk.pop_back();
        }
      }
    }

    while (!stk.empty()) {
      if (stk.back() == '(') {
        ans += 2;
        stk.pop_back();
      } else {
        ans += 1;
        stk.pop_back();
        stk.pop_back();
      }
    }

    return ans;
  }
};
// Runtime: 168 ms, faster than 100.00%
// Memory Usage: 13.4 MB, less than 50.00%

class Solution {
 public:
  int minInsertions(string s) {
    vector<char> stk;

    int ans = 0;

    for (auto ch : s) {
      if (ch == '(') {
        if (stk.empty() || stk.back() == '(') {
          stk.push_back(ch);
        } else {
          ++ans;

          stk.pop_back();
        }
      } else {
        if (stk.empty()) {
          ++ans;

          stk.push_back('(');
          stk.push_back(ch);
        } else if (stk.back() == '(') {
          stk.push_back(ch);
        } else {
          stk.pop_back();
          stk.pop_back();
        }
      }
    }

    while (!stk.empty()) {
      if (stk.back() == '(') {
        ans += 2;
        stk.pop_back();
      } else {
        ans += 1;
        stk.pop_back();
        stk.pop_back();
      }
    }

    return ans;
  }
};
// Runtime: 168 ms, faster than 100.00%
// Memory Usage: 13 MB, less than 50.00%