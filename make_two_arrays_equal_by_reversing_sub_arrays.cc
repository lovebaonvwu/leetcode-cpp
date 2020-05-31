class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    int sum = 0;

    for (int i = 0; i < target.size(); ++i) {
      sum ^= target[i];
      sum ^= arr[i];
    }

    return sum == 0;
  }
};
// Runtime: 20 ms, faster than 75.00%
// Memory Usage: 14.2 MB, less than 100.00%

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    int sum = 0;

    for (int i = 0; i < target.size(); ++i) {
      sum ^= target[i] ^ arr[i];
    }

    return sum == 0;
  }
};
// Runtime: 16 ms, faster than 100.00%
// Memory Usage: 14 MB, less than 100.00%