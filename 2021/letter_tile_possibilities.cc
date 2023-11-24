class Solution {
  unordered_set<string> st;

 public:
  int numTilePossibilities(string tiles) {
    int cnt[26] = {0};

    for (auto c : tiles) {
      ++cnt[c - 'A'];
    }

    dfs(cnt, "");

    return st.size();
  }

  void dfs(int cnt[26], string s) {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        --cnt[i];
        s += (char)(i + 'A');

        st.insert(s);

        dfs(cnt, s);

        s.pop_back();
        ++cnt[i];
      }
    }
  }
};
// Runtime: 40 ms, faster than 52.31%
// Memory Usage: 14.9 MB, less than 44.94%

class Solution {
  int ans = 0;

 public:
  int numTilePossibilities(string tiles) {
    int cnt[26] = {0};

    for (auto c : tiles) {
      ++cnt[c - 'A'];
    }

    dfs(cnt);

    return ans;
  }

  void dfs(int cnt[26]) {
    for (int i = 0; i < 26; ++i) {
      if (cnt[i]) {
        --cnt[i];

        ++ans;

        dfs(cnt);

        ++cnt[i];
      }
    }
  }
};
// Runtime: 4 ms, faster than 95.95%
// Memory Usage: 6.2 MB, less than 98.55%