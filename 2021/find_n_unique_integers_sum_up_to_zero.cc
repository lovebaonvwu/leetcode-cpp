class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> ans;

    if (n % 2 != 0) {
      ans.push_back(0);
      --n;
    }

    int i = 1;
    while (n > 0) {
      ans.push_back(i);
      ans.push_back(-i);

      n -= 2;
      ++i;
    }

    return ans;
  }
};
// Runtime: 4 ms, faster than 98.76%
// Memory Usage: 8.7 MB, less than 100.00%

class Solution {
 public:
  vector<int> sumZero(int n) {
    vector<int> ans(n);

    int sum = 0;

    for (int i = 1; i < n; ++i) {
      ans[i] = i;
      sum += i;
    }

    ans[0] = -sum;

    return ans;
  }
};
// Runtime: 8 ms, faster than 58.78%
// Memory Usage: 8.8 MB, less than 100.00%