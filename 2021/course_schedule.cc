class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> mp;
    vector<int> indegree(numCourses);

    for (auto& p : prerequisites) {
      ++indegree[p[0]];

      mp[p[1]].push_back(p[0]);
    }

    int k = numCourses;
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        --k;
        q.push(i);
      }
    }

    while (!q.empty() && k > 0) {
      int c = q.front();
      q.pop();

      for (auto n : mp[c]) {
        --indegree[n];

        if (indegree[n] == 0) {
          --k;
          q.push(n);
        }
      }
    }

    return k == 0;
  }
};
// Runtime: 44 ms, faster than 64.92%
// Memory Usage: 14.1 MB, less than 47.38%