class Solution {
 public:
  int calculate(string s) {
    deque<int> nums;
    queue<char> ops;

    int num = 0;
    char prev_op;

    s.append("x");
    for (auto c : s) {
      if (isspace(c)) {
        continue;
      }

      if (c == '*' || c == '/' || c == '+' || c == '-' || c == 'x') {
        if (prev_op == '*') {
          nums[nums.size() - 1] = nums.back() * num;
        } else if (prev_op == '/') {
          nums[nums.size() - 1] = nums.back() / num;
        } else {
          nums.push_back(num);
        }
        num = 0;
        prev_op = c;
      } else {
        num = num * 10 + (c - '0');
      }

      if (c == '+' || c == '-') {
        ops.push(c);
      }
    }

    int ans = nums.front();
    nums.pop_front();

    while (!ops.empty()) {
      auto op = ops.front();
      ops.pop();

      num = nums.front();
      nums.pop_front();

      if (op == '+') {
        ans += num;
      } else {
        ans -= num;
      }
    }

    return ans;
  }
};
// Runtime: 16 ms, faster than 49.31%
// Memory Usage: 9.5 MB, less than 20.08%

class Solution {
 public:
  int calculate(string s) {
    stack<int> stk;

    int num = 0;
    char op = '+';
    s += '+';

    for (auto c : s) {
      if (isdigit(c)) {
        num = num * 10 + (c - '0');
      }

      if (c == '+' || c == '-' || c == '*' || c == '/') {
        if (op == '+') {
          stk.push(num);
        } else if (op == '-') {
          stk.push(-num);
        } else if (op == '*') {
          num *= stk.top();
          stk.pop();

          stk.push(num);
        } else {
          num = stk.top() / num;
          stk.pop();

          stk.push(num);
        }

        op = c;
        num = 0;
      }
    }

    int ans = 0;
    while (!stk.empty()) {
      ans += stk.top();
      stk.pop();
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 76.51%
// Memory Usage: 9.3 MB, less than 28.57%