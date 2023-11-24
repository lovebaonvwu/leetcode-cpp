class Solution {
  vector<int> ans;

 public:
  vector<int> sequentialDigits(int low, int high) {
    for (int i = 1; i <= 9; ++i) {
      dfs(i, i, low, high);
    }
    sort(ans.begin(), ans.end());

    return ans;
  }

  void dfs(int n, int last, int low, int high) {
    if (n > high) {
      return;
    }

    if (n >= low && n <= high) {
      ans.push_back(n);
    }

    if (last == 9) {
      return;
    }

    dfs(n * 10 + last + 1, last + 1, low, high);
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.3 MB, less than 42.52%

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;

    queue<int> q;

    for (int i = 1; i < 10; ++i) {
      q.push(i);
    }

    while (!q.empty()) {
      int n = q.front();
      q.pop();

      if (n >= low && n <= high) {
        ans.push_back(n);
      }

      int r = n % 10;
      if (r < 9) {
        q.push(n * 10 + r + 1);
      }
    }

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.4 MB, less than 8.79%

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> ans;

    for (int i = 1; i < 10; ++i) {
      int n = 0;
      for (int j = i; j < 10; ++j) {
        n = n * 10 + j;

        if (n >= low && n <= high) {
          ans.push_back(n);
        }
      }
    }

    sort(ans.begin(), ans.end());

    return ans;
  }
};
// Runtime: 0 ms, faster than 100.00%
// Memory Usage: 6.2 MB, less than 51.07%