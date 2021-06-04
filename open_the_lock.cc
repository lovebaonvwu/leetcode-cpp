class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    queue<string> q;
    q.push("0000");

    unordered_set<string> visited;

    for (auto s : deadends) {
      visited.insert(s);
    }

    int ans = 0;

    while (!q.empty()) {
      int cnt = q.size();

      while (cnt-- > 0) {
        auto cur = q.front();
        q.pop();

        if (visited.count(cur)) {
          continue;
        }

        visited.insert(cur);

        if (cur == target) {
          return ans;
        }

        for (int i = 0; i < cur.size(); ++i) {
          for (auto j : {1, 9}) {
            string tmp = cur;

            tmp[i] = ((tmp[i] - '0') + j) % 10 + '0';

            q.push(tmp);
          }
        }
      }

      ++ans;
    }

    return -1;
  }
};
// Runtime: 212 ms, faster than 53.05%
// Memory Usage: 73.9 MB, less than 24.17%