class Solution {
 public:
  int countOdds(int low, int high) {
    int ans = 0;

    if (low & 1 && high & 1) {
      ans = (high - low) / 2 + 1;
    } else {
      ans = (high - low) / 2;
      ans += (high - low) & 1;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%

class Solution {
 public:
  int countOdds(int low, int high) {
    int ans = 0;

    if (low & 1 || high & 1) {
      ans = (high - low) / 2 + 1;
    } else {
      ans = (high - low) / 2;
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6 MB, less than 100.00%

class Solution {
 public:
  int countOdds(int low, int high) {
    return low & 1 || high & 1 ? (high - low) / 2 + 1 : (high - low) / 2;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%

class Solution {
 public:
  int countOdds(int low, int high) {
    return (high - low) / 2 + ((low | high) & 1);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 5.9 MB, less than 100.00%