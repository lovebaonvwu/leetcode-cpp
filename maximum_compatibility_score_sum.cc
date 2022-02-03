class Solution {
  int ans = 0;

 public:
  int maxCompatibilitySum(vector<vector<int>>& students,
                          vector<vector<int>>& mentors) {
    dfs(students, mentors, {}, 0, 0);

    return ans;
  }

  void dfs(vector<vector<int>>& students,
           vector<vector<int>>& mentors,
           unordered_set<int> visited,
           int i,
           int score) {
    if (visited.size() == mentors.size()) {
      ans = max(ans, score);
      return;
    }

    for (int j = 0; j < mentors.size(); ++j) {
      if (visited.find(j) != visited.end()) {
        continue;
      }

      visited.insert(j);
      int cnt = 0;
      for (int k = 0; k < students[i].size(); ++k) {
        cnt += students[i][k] == mentors[j][k];
      }

      dfs(students, mentors, visited, i + 1, score + cnt);
      visited.erase(j);
    }
  }
};
// Time Limit Exceeded
// 2022.2.3 at 茗筑美嘉

class Solution {
  int ans = 0;

 public:
  int maxCompatibilitySum(vector<vector<int>>& students,
                          vector<vector<int>>& mentors) {
    int visited[8] = {0};

    dfs(students, mentors, visited, 0, 0);

    return ans;
  }

  void dfs(vector<vector<int>>& students,
           vector<vector<int>>& mentors,
           int* visited,
           int i,
           int score) {
    if (i == students.size()) {
      ans = max(ans, score);
      return;
    }

    for (int j = 0; j < mentors.size(); ++j) {
      if (visited[j]) {
        continue;
      }

      visited[j] = 1;

      int cnt = 0;
      for (int k = 0; k < students[i].size(); ++k) {
        cnt += students[i][k] == mentors[j][k];
      }

      dfs(students, mentors, visited, i + 1, score + cnt);
      visited[j] = 0;
    }
  }
};
// Runtime: 278 ms, faster than 34.17%
// Memory Usage: 10.1 MB, less than 47.74%
// 2022.2.3 at 茗筑美嘉