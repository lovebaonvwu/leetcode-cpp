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

class Solution {
 public:
  bool canBeEqual(vector<int>& target, vector<int>& arr) {
    vector<int> cnt(1001);

    for (int i = 0; i < target.size(); ++i) {
      ++cnt[target[i]];
      --cnt[arr[i]];
    }

    return (all_of(cnt.begin(), cnt.end(), [](int n) { return n == 0; }));
  }
};
// Runtime: 16 ms, faster than 100.00%
// Memory Usage: 14.6 MB, less than 100.00%