class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j != i && boxes[j] == '1') {
          ans[i] += abs(i - j);
        }
      }
    }

    return ans;
  }
};
// Runtime: 300 ms, faster than 25.00%
// Memory Usage: 8.9 MB, less than 50.00%

class Solution {
 public:
  vector<int> minOperations(string boxes) {
    int n = boxes.size();

    vector<int> ans(n);

    for (int i = 0, cnt = 0, ops = 0; i < n; ++i) {
      ans[i] += ops;

      cnt += boxes[i] - '0';

      ops += cnt;
    }

    for (int i = n - 1, cnt = 0, ops = 0; i >= 0; --i) {
      ans[i] += ops;

      cnt += boxes[i] - '0';

      ops += cnt;
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 75.00%
// Memory Usage: 8.7 MB, less than 100.00%