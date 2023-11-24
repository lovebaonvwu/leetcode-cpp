class Solution {
  vector<string> happy;

 public:
  string getHappyString(int n, int k) {
    dfs("", n);

    sort(happy.begin(), happy.end());

    return k > happy.size() ? "" : happy[k - 1];
  }

  void dfs(string s, int n) {
    if (s.size() == n) {
      happy.push_back(s);
      return;
    }

    if (s.empty() || s.back() != 'a') {
      dfs(s + 'a', n);
    }

    if (s.empty() || s.back() != 'b') {
      dfs(s + 'b', n);
    }

    if (s.empty() || s.back() != 'c') {
      dfs(s + 'c', n);
    }
  }
};
// Runtime: 244 ms, faster than 14.29%
// Memory Usage: 22.7 MB, less than 100.00%

class Solution {
  priority_queue<string> happy;

 public:
  string getHappyString(int n, int k) {
    dfs("", n, k);

    return k > happy.size() ? "" : happy.top();
  }

  void dfs(string s, int n, int k) {
    if (s.size() == n) {
      happy.push(s);
      if (happy.size() > k) {
        happy.pop();
      }
      return;
    }

    if (s.empty() || s.back() != 'a') {
      dfs(s + 'a', n, k);
    }

    if (s.empty() || s.back() != 'b') {
      dfs(s + 'b', n, k);
    }

    if (s.empty() || s.back() != 'c') {
      dfs(s + 'c', n, k);
    }
  }
};
// Runtime: 364 ms, faster than 14.29%
// Memory Usage: 8.3 MB, less than 100.00%

class Solution {
  vector<string> happy;

 public:
  string getHappyString(int n, int k) {
    dfs("", n, k);

    return k > happy.size() ? "" : happy.back();
  }

  void dfs(string s, int n, int k) {
    if (s.size() == n) {
      happy.push_back(s);
      return;
    }

    if (happy.size() < k && (s.empty() || s.back() != 'a')) {
      dfs(s + 'a', n, k);
    }

    if (happy.size() < k && (s.empty() || s.back() != 'b')) {
      dfs(s + 'b', n, k);
    }

    if (happy.size() < k && (s.empty() || s.back() != 'c')) {
      dfs(s + 'c', n, k);
    }
  }
};
// Runtime: 24 ms, faster than 28.57%
// Memory Usage: 8.2 MB, less than 100.00%

class Solution {
  string ans;

 public:
  string getHappyString(int n, int k) {
    dfs("", n, k);

    return k > 0 ? "" : ans;
  }

  void dfs(string s, int n, int& k) {
    if (s.size() == n) {
      --k;
      ans = s;
      return;
    }

    if (k > 0 && (s.empty() || s.back() != 'a')) {
      dfs(s + 'a', n, k);
    }

    if (k > 0 && (s.empty() || s.back() != 'b')) {
      dfs(s + 'b', n, k);
    }

    if (k > 0 && (s.empty() || s.back() != 'c')) {
      dfs(s + 'c', n, k);
    }
  }
};
// Runtime: 12 ms, faster than 28.57%
// Memory Usage: 6 MB, less than 100.00%