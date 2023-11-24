class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> pre;
    vector<int> courses(numCourses);

    for (auto& p : prerequisites) {
      pre[p[1]].push_back(p[0]);
      ++courses[p[0]];
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < numCourses; ++i) {
      if (courses[i] == 0) {
        q.push(i);
        ans.push_back(i);
      }
    }

    while (!q.empty()) {
      auto c = pre[q.front()];
      q.pop();

      for (int i = 0; i < c.size(); ++i) {
        --courses[c[i]];

        if (courses[c[i]] == 0) {
          ans.push_back(c[i]);

          if (ans.size() == numCourses) {
            return ans;
          }

          q.push(c[i]);
        }
      }
    }

    if (ans.size() != numCourses) {
      return {};
    }

    return ans;
  }
};
// Runtime: 40 ms, faster than 90.06%
// Memory Usage: 14.3 MB, less than 51.99%

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> pre;
    vector<int> courses(numCourses);

    for (auto& p : prerequisites) {
      pre[p[1]].push_back(p[0]);
      ++courses[p[0]];
    }

    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < numCourses; ++i) {
      if (courses[i] == 0) {
        q.push(i);
        ans.push_back(i);
      }
    }

    while (!q.empty()) {
      auto c = pre[q.front()];
      q.pop();

      for (int i = 0; i < c.size(); ++i) {
        --courses[c[i]];

        if (courses[c[i]] == 0) {
          ans.push_back(c[i]);

          if (ans.size() == numCourses) {
            return ans;
          }

          q.push(c[i]);
        }
      }
    }

    return ans.size() != numCourses ? vector<int>() : ans;
  }
};
// Runtime: 44 ms, faster than 74.84%
// Memory Usage: 14.4 MB, less than 48.56%