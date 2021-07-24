class Solution {
  vector<vector<string>> ans;
  unordered_map<string, vector<string>> prev;

 public:
  vector<vector<string>> findLadders(string beginWord,
                                     string endWord,
                                     vector<string>& wordList) {
    unordered_map<string, vector<string>> mp;
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.insert(beginWord);

    for (auto w : st) {
      string tmp = w;

      for (auto& c : w) {
        char org = c;

        for (int i = 'a'; i <= 'z'; ++i) {
          if (i == org) {
            continue;
          }
          c = i;
          if (st.find(w) != st.end()) {
            mp[tmp].push_back(w);
          }
        }

        c = org;
      }
    }

    queue<string> q;
    q.push(beginWord);

    unordered_set<string> visited;
    visited.insert(beginWord);

    bool found = false;

    while (!q.empty() && !found) {
      int cnt = q.size();

      unordered_set<string> whatWeFound;

      while (cnt-- > 0) {
        auto cur = q.front();
        q.pop();

        for (auto next : mp[cur]) {
          if (visited.find(next) != visited.end()) {
            continue;
          }

          whatWeFound.insert(next);
          prev[next].push_back(cur);

          if (next == endWord) {
            found = true;
          }
        }
      }

      for (auto what : whatWeFound) {
        visited.insert(what);
        q.push(what);
      }
    }

    vector<string> path({endWord});

    dfs(path, endWord, beginWord);

    return ans;
  }

  void dfs(vector<string> path, string cur, string target) {
    if (cur == target) {
      reverse(path.begin(), path.end());

      ans.push_back(path);
      return;
    }

    for (auto w : prev[cur]) {
      vector<string> tmp = path;
      tmp.push_back(w);
      dfs(tmp, w, target);
    }
  }
};
// Runtime: 13 ms, faster than 58.83%
// Memory Usage: 11 MB, less than 41.85%
// 2021.7.24 at 茗筑美嘉