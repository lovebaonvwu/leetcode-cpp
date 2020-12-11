class Solution {
 public:
  string interpret(string command) {
    string ans;

    for (int i = 0; i < command.size();) {
      if (command[i] == 'G') {
        ans += "G";
        i += 1;
      } else if (command[i] == '(' && command[i + 1] == ')') {
        ans += "o";
        i += 2;
      } else if (command[i] == '(' && command[i + 1] == 'a') {
        ans += "al";
        i += 4;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.5 MB, less than 40.88%

class Solution {
 public:
  string interpret(string command) {
    string ans;

    for (int i = 0; i < command.size();) {
      if (command[i] == 'G') {
        ans += "G";
        i += 1;
      } else if (command[i + 1] == ')') {
        ans += "o";
        i += 2;
      } else {
        ans += "al";
        i += 4;
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 40.88%