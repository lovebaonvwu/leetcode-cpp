class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int b5 = 0;
    int b10 = 0;

    for (const auto& b : bills) {
      if (b == 5)
        ++b5;
      else if (b == 10)
        ++b10, --b5;
      else if (b10 > 0)
        --b10, --b5;
      else
        b5 -= 3;

      if (b5 < 0)
        return false;
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 78.10%
// Memory Usage: 9.7 MB, less than 100.00%

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int b5 = 0;
    int b10 = 0;

    for (const auto& b : bills) {
      if (b == 5) {
        ++b5;
      } else if (b == 10) {
        ++b10;
        --b5;
      } else {
        if (b10 > 0) {
          --b10;
          --b5;
        } else {
          b5 -= 3;
        }
      }

      if (b5 < 0) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 78.10%
// Memory Usage: 9.8 MB, less than 83.33%

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    int b5 = 0;
    int b10 = 0;

    for (const auto& b : bills) {
      if (b == 5) {
        ++b5;
      } else if (b == 10) {
        if (b5 == 0) {
          return false;
        }

        ++b10;
        --b5;
      } else {
        if (b10 != 0 && b5 != 0) {
          --b10;
          --b5;
        } else if (b10 == 0 && b5 > 2) {
          b5 -= 3;
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 78.10%
// Memory Usage: 9.6 MB, less than 100.00%

class Solution {
 public:
  bool lemonadeChange(vector<int>& bills) {
    stack<int> b5;
    stack<int> b10;

    for (const auto& b : bills) {
      if (b == 5) {
        b5.push(b);
      } else if (b == 10) {
        if (b5.empty()) {
          return false;
        }

        b10.push(b);
        b5.pop();
      } else {
        if (!b10.empty() && !b5.empty()) {
          b10.pop();
          b5.pop();
        } else if (b10.empty() && b5.size() > 2) {
          b5.pop();
          b5.pop();
          b5.pop();
        } else {
          return false;
        }
      }
    }

    return true;
  }
};
// Runtime: 16 ms, faster than 78.10%
// Memory Usage: 10 MB, less than 16.67%