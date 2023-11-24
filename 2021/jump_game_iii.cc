class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<vector<int>> mem(arr.size(), vector<int>(2));

    return dfs(mem, arr, start);
  }

  bool dfs(vector<vector<int>>& mem, vector<int>& arr, int start) {
    if (start < 0 || start >= arr.size()) {
      return false;
    }

    if (arr[start] == 0) {
      return true;
    }

    if (mem[start][1]) {
      return false;
    }

    bool b1 = dfs(mem, arr, start + arr[start]);
    if (b1) {
      return true;
    }
    mem[start][1] = 1;

    if (mem[start][0]) {
      return false;
    }

    bool b2 = dfs(mem, arr, start - arr[start]);
    if (b2) {
      return true;
    }
    mem[start][0] = 1;

    return false;
  }
};
// Runtime: 108 ms, faster than 5.38%
// Memory Usage: 23.8 MB, less than 100.00%

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<int> mem(arr.size());

    return dfs(mem, arr, start);
  }

  bool dfs(vector<int>& mem, vector<int>& arr, int start) {
    if (start < 0 || start >= arr.size()) {
      return false;
    }

    if (arr[start] == 0) {
      return true;
    }

    if (mem[start]) {
      return false;
    }

    bool b1 = dfs(mem, arr, start + arr[start]);
    if (b1) {
      return true;
    }
    mem[start] = 1;

    return dfs(mem, arr, start - arr[start]);
  }
};
// Runtime: 44 ms, faster than 97.68%
// Memory Usage: 10.9 MB, less than 100.00%

class Solution {
  unordered_set<int> visited;

 public:
  bool canReach(vector<int>& arr, int start) {
    if (start >= 0 && start < arr.size() && visited.insert(start).second) {
      return arr[start] == 0 || canReach(arr, start + arr[start]) ||
             canReach(arr, start - arr[start]);
    }

    return false;
  }
};
// Runtime: 52 ms, faster than 67.27%
// Memory Usage: 10.6 MB, less than 100.00%

class Solution {
 public:
  bool canReach(vector<int>& arr, int start) {
    vector<bool> visited(arr.size());

    queue<int> q;
    q.push(start);

    while (!q.empty()) {
      int idx = q.front();
      q.pop();

      if (visited[idx]) {
        continue;
      }

      if (arr[idx] == 0) {
        return true;
      }

      visited[idx] = true;

      if (idx + arr[idx] < arr.size()) {
        q.push(idx + arr[idx]);
      }

      if (idx - arr[idx] >= 0) {
        q.push(idx - arr[idx]);
      }
    }

    return false;
  }
};
// Runtime: 52 ms, faster than 67.27%
// Memory Usage: 10.2 MB, less than 100.00%