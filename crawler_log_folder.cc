class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ans = 0;

    for (auto& s : logs) {
      if (s == "../") {
        ans -= ans > 0;
      } else if (s == "./") {
      } else {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 89.62%
// Memory Usage: 10.8 MB, less than 48.37%

class Solution {
 public:
  int minOperations(vector<string>& logs) {
    int ans = 0;

    for (auto& s : logs) {
      if (s == "./") {
        continue;
      }

      if (s == "../") {
        ans -= ans > 0;
      } else {
        ++ans;
      }
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 89.62%
// Memory Usage: 10.8 MB, less than 40.92%