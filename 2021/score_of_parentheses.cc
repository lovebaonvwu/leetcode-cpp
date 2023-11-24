class Solution {
 public:
  int scoreOfParentheses(string S) {
    stack<int> stk;

    stk.push(0);

    for (const auto& ch : S) {
      if (ch == '(') {
        stk.push(0);
        continue;
      }

      int score = stk.top();
      stk.pop();

      if (score == 0) {
        score = 1;
      } else {
        score *= 2;
      }

      stk.top() += score;
    }

    return stk.top();
  }
};
// Runtime: 4 ms, faster than 54.13%
// Memory Usage: 8.3 MB, less than 100.00%

class Solution {
 public:
  int scoreOfParentheses(string S) { return calc(S, 0, S.size() - 1); }

  int calc(string& s, int begin, int end) {
    int score = 0;

    while (begin < end) {
      if (s[begin] == '(' && s[begin + 1] == ')') {
        ++score;
        begin += 2;
        continue;
      }

      int tmp = 1;
      int idx = begin + 1;
      while (tmp) {
        if (s[idx] == '(') {
          ++tmp;
        } else {
          --tmp;
        }
        ++idx;
      }

      score += 2 * calc(s, begin + 1, idx - 2);

      begin = idx;
    }

    return score;
  }
};
// Runtime: 4 ms, faster than 54.13%
// Memory Usage: 8.2 MB, less than 100.00%