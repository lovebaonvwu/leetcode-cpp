class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    int i = 0;

    for (int j = 0; j < typed.size(); ++j) {
      if (i < name.size() && name[i] == typed[j]) {
        ++i;
      } else if (j == 0 || typed[j] != typed[j - 1]) {
        return false;
      }
    }

    return i == name.size();
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.5 MB, less than 71.43%

class Solution {
 public:
  bool isLongPressedName(string name, string typed) {
    if (name.empty() && typed.empty()) {
      return true;
    }

    if (name.empty() || typed.empty()) {
      return false;
    }

    if (name[0] != typed[0]) {
      return false;
    }

    char prev = name[0];

    int i = 1;
    int j = 1;

    while (i < name.size()) {
      if (name[i] != typed[j]) {
        if (typed[j] == prev) {
          ++j;
        } else {
          return false;
        }
      } else {
        prev = name[i];
        ++i;
        ++j;
      }
    }

    while (j < typed.size()) {
      if (typed[j++] != prev) {
        return false;
      }
    }

    return true;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 8.3 MB, less than 100.00%